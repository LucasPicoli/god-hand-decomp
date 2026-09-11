/* ee-2.9-991111 matched TU. */

/* MATCH (exact), 2380 B.  Wave 23 lane G, 2026-09-07.
 * newlib libm kf_rem_pio2.c -- __kernel_rem_pio2f.  Donor: sce_crt_libm/kf_rem_pio2.o.
 *
 *   compiler:         ee-2.9-991111
 *   assembler:        ee (default)
 *   fp_hazard_rules:  "libm-mtc1,cmppad"
 *
 *   python3 .private/scripts/score_candidate.py __kernel_rem_pio2f <this file> \
 *           --compiler ee-2.9-991111 --fp-hazard-rules libm-mtc1,cmppad
 *   -> MATCH (exact)
 *
 * The BODY is worker D3's, unchanged.  Only the wrapper moved.
 *   `libm-mtc1` = `libm` without its `mfc1`-after-convert pad, which this
 *   object does not carry (retail pads that pair at 3 of 419 sites in the
 *   binary and at none of this object's three).  It closes 8 of the 12 words.
 *   `cmppad` supplies the nop retail has at 0x003A4238.  cc1 emits NO `#nop`
 *   hint there because a LABEL ($L183) sits between the compare and the
 *   branch, so `_materialize_hazard_nops` had nothing to uncomment.
 *
 * D3 parked this as "one nop on the wrong side of one compare".  That reading
 * was wrong in kind: retail pads BOTH the mtc1 site and the compare site
 * nowhere -- it pads the compare only, and the hint for it never existed.
 */
/* newlib libm kf_rem_pio2.c -- __kernel_rem_pio2f */

extern float scalbnf(float, int);
extern float floorf(float);	/* floorf */
extern const int D_0045EF90[3];		/* init_jk = {4,7,9} */
extern const float D_0045EFA0[];	/* PIo2[] */
#define init_jk D_0045EF90
#define PIo2    D_0045EFA0

#define zero	((float)0.0)
#define one	((float)1.0)
#define two8	((float)256.0)		/* 0x43800000 */
#define twon8	((float)0.00390625)	/* 0x3B800000 */

__attribute__((section(".text.__kernel_rem_pio2f")))
int __kernel_rem_pio2f(float *x, float *y, int e0, int nx, int prec, const int *ipio2)
{
	int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	float z,fw,f[20],fq[20],q[20];

    /* initialize jk*/
	jk = init_jk[prec];
	jp = jk;

    /* determine jx,jv,q0, note that 3>q0 */
	jx =  nx-1;
	jv = (e0-3)/8; if(jv<0) jv=0;
	q0 =  e0-8*(jv+1);

    /* set up f[0] to f[jx+jk] where f[jx+jk] = ipio2[jv+jk] */
	j = jv-jx;	m = jx+jk;
	for(i=0;i<=m;i++,j++) f[i] = (j<0)? zero : (float) ipio2[j];

    /* compute q[0],q[1],...q[jk] */
	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
    /* distill q[] into iq[] reversingly */
	for(i=0,j=jz,z=q[jz];j>0;i++,j--) {
	    fw    =  (float)((int)(twon8* z));
	    iq[i] =  (int)(z-two8*fw);
	    z     =  q[j-1]+fw;
	}

    /* compute n */
	z  = scalbnf(z,q0);		/* actual value of z */
	z -= (float)8.0*floorf(z*(float)0.125);	/* trim off integer >= 8 */
	n  = (int) z;
	z -= (float)n;
	ih = 0;
	if(q0>0) {	/* need iq[jz-1] to determine n */
	    i  = (iq[jz-1]>>(8-q0)); n += i;
	    iq[jz-1] -= i<<(8-q0);
	    ih = iq[jz-1]>>(7-q0);
	}
	else if(q0==0) ih = iq[jz-1]>>8;
	else if(z>=(float)0.5) ih=2;

	if(ih>0) {	/* q > 0.5 */
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {	/* compute 1-q */
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x100- j;
		    }
		} else  iq[i] = 0xff - j;
	    }
	    if(q0>0) {		/* rare case: chance is 1 in 12 */
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7f; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3f; break;
	        }
	    }
	    if(ih==2) {
		z = one - z;
		if(carry!=0) z -= scalbnf(one,q0);
	    }
	}

    /* check if recomputation is needed */
	if(z==zero) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) { /* need recomputation */
		for(k=1;iq[jk-k]==0;k++);   /* k = no. of terms needed */

		for(i=jz+1;i<=jz+k;i++) {   /* add q[jz+1] to q[jz+k] */
		    f[jx+i] = (float) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

    /* chop off zero terms */
	if(z==(float)0.0) {
	    jz -= 1; q0 -= 8;
	    while(iq[jz]==0) { jz--; q0-=8;}
	} else { /* break z into 8-bit if necessary */
	    z = scalbnf(z,-q0);
	    if(z>=two8) {
		fw = (float)((int)(twon8*z));
		iq[jz] = (int)(z-two8*fw);
		jz += 1; q0 += 8;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

    /* convert integer "bit" chunk to floating-point value */
	fw = scalbnf(one,q0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(float)iq[i]; fw*=twon8;
	}

    /* compute PIo2[0,...,jp]*q[jz,...,0] */
	for(i=jz;i>=0;i--) {
	    for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += PIo2[k]*q[i+k];
	    fq[jz-i] = fw;
	}

    /* compress fq[] into y[] */
	switch(prec) {
	    case 0:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		break;
	    case 1:
	    case 2:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		fw = fq[0]-fw;
		for (i=1;i<=jz;i++) fw += fq[i];
		y[1] = (ih==0)? fw: -fw;
		break;
	    case 3:	/* painful */
		for (i=jz;i>0;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (i=jz;i>1;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (fw=0.0,i=jz;i>=2;i--) fw += fq[i];
		if(ih==0) {
		    y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
		} else {
		    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
		}
	}
	return n&7;
}
