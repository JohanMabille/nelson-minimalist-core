/* Translated by Nelson f2c (version 20170901).
   You must link the resulting object file with the libraries:
	-lnlsf2c -lm   (in that order)
*/

#include "nelson_f2c.h"

/* Table of constant values */

static doublecomplex c_b1 = {0.,0.};
static doublecomplex c_b2 = {1.,0.};
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c__1 = 1;

/* Subroutine */ EXPORTSYMBOL int ab08nz_(equil, n, m, p, a, lda, b, ldb, c__, ldc, d__, ldd, nu, rank, dinfz, nkror, nkrol, infz, kronr, kronl, af, ldaf, bf, ldbf, tol, iwork, dwork, zwork, lzwork, info, equil_len)
char *equil;
integer *n, *m, *p;
doublecomplex *a;
integer *lda;
doublecomplex *b;
integer *ldb;
doublecomplex *c__;
integer *ldc;
doublecomplex *d__;
integer *ldd, *nu, *rank, *dinfz, *nkror, *nkrol, *infz, *kronr, *kronl;
doublecomplex *af;
integer *ldaf;
doublecomplex *bf;
integer *ldbf;
doublereal *tol;
integer *iwork;
doublereal *dwork;
doublecomplex *zwork;
integer *lzwork, *info;
ftnlen equil_len;
{
    /* System generated locals */
    integer a_dim1, a_offset, af_dim1, af_offset, b_dim1, b_offset, bf_dim1, bf_offset, c_dim1, c_offset, d_dim1, d_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7;
    /* Builtin functions */
    double sqrt();
    /* Local variables */
    static integer numu, numu1, i__, j, sigma;
    extern logical lsame_();
    extern /* Subroutine */ EXPORTSYMBOL int tb01iz_();
    static integer ninfz;
    static doublereal toler;
    static integer i1;
    extern /* Subroutine */ EXPORTSYMBOL int zcopy_(), ab8nxz_();
    static integer nb, ii;
    extern doublereal dlamch_();
    static integer mm, nn, pp, ro, mu;
    extern /* Subroutine */ EXPORTSYMBOL int xerbla_();
    extern integer ilaenv_();
    static doublereal maxred;
    extern doublereal zlange_();
    static logical lequil;
    static doublereal thresh;
    extern /* Subroutine */ EXPORTSYMBOL int zlacpy_(), zlaset_();
    static doublereal svlmax;
    static logical lquery;
    static integer nu1, wrkopt;
    extern /* Subroutine */ EXPORTSYMBOL int zunmrz_(), ztzrzf_();
    static integer mnu;
    /*     SLICOT RELEASE 5.0. */
    /*     Copyright (c) 2002-2010 NICONET e.V. */
    /*     This program is free software: you can redistribute it and/or */
    /*     modify it under the terms of the GNU General Public License as */
    /*     published by the Free Software Foundation, either version 2 of */
    /*     the License, or (at your option) any later version. */
    /*     This program is distributed in the hope that it will be useful, */
    /*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
    /*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
    /*     GNU General Public License for more details. */
    /*     You should have received a copy of the GNU General Public License */
    /*     along with this program.  If not, see */
    /*     <http://www.gnu.org/licenses/>. */
    /*     PURPOSE */
    /*     To construct for a linear multivariable system described by a */
    /*     state-space model (A,B,C,D) a regular pencil (A - lambda*B ) which */
    /*                                                    f          f */
    /*     has the invariant zeros of the system as generalized eigenvalues. */
    /*     The routine also computes the orders of the infinite zeros and the */
    /*     right and left Kronecker indices of the system (A,B,C,D). */
    /*     ARGUMENTS */
    /*     Mode Parameters */
    /*     EQUIL   CHARACTER*1 */
    /*             Specifies whether the user wishes to balance the compound */
    /*             matrix (see METHOD) as follows: */
    /*             = 'S':  Perform balancing (scaling); */
    /*             = 'N':  Do not perform balancing. */
    /*     Input/Output Parameters */
    /*     N       (input) INTEGER */
    /*             The number of state variables, i.e., the order of the */
    /*             matrix A.  N >= 0. */
    /*     M       (input) INTEGER */
    /*             The number of system inputs.  M >= 0. */
    /*     P       (input) INTEGER */
    /*             The number of system outputs.  P >= 0. */
    /*     A       (input) COMPLEX*16 array, dimension (LDA,N) */
    /*             The leading N-by-N part of this array must contain the */
    /*             state dynamics matrix A of the system. */
    /*     LDA     INTEGER */
    /*             The leading dimension of array A.  LDA >= MAX(1,N). */
    /*     B       (input) COMPLEX*16 array, dimension (LDB,M) */
    /*             The leading N-by-M part of this array must contain the */
    /*             input/state matrix B of the system. */
    /*     LDB     INTEGER */
    /*             The leading dimension of array B.  LDB >= MAX(1,N). */
    /*     C       (input) COMPLEX*16 array, dimension (LDC,N) */
    /*             The leading P-by-N part of this array must contain the */
    /*             state/output matrix C of the system. */
    /*     LDC     INTEGER */
    /*             The leading dimension of array C.  LDC >= MAX(1,P). */
    /*     D       (input) COMPLEX*16 array, dimension (LDD,M) */
    /*             The leading P-by-M part of this array must contain the */
    /*             direct transmission matrix D of the system. */
    /*     LDD     INTEGER */
    /*             The leading dimension of array D.  LDD >= MAX(1,P). */
    /*     NU      (output) INTEGER */
    /*             The number of (finite) invariant zeros. */
    /*     RANK    (output) INTEGER */
    /*             The normal rank of the transfer function matrix. */
    /*     DINFZ   (output) INTEGER */
    /*             The maximum degree of infinite elementary divisors. */
    /*     NKROR   (output) INTEGER */
    /*             The number of right Kronecker indices. */
    /*     NKROL   (output) INTEGER */
    /*             The number of left Kronecker indices. */
    /*     INFZ    (output) INTEGER array, dimension (N) */
    /*             The leading DINFZ elements of INFZ contain information */
    /*             on the infinite elementary divisors as follows: */
    /*             the system has INFZ(i) infinite elementary divisors */
    /*             of degree i, where i = 1,2,...,DINFZ. */
    /*     KRONR   (output) INTEGER array, dimension (MAX(N,M)+1) */
    /*             The leading NKROR elements of this array contain the */
    /*             right Kronecker (column) indices. */
    /*     KRONL   (output) INTEGER array, dimension (MAX(N,P)+1) */
    /*             The leading NKROL elements of this array contain the */
    /*             left Kronecker (row) indices. */
    /*     AF      (output) COMPLEX*16 array, dimension (LDAF,N+MIN(P,M)) */
    /*             The leading NU-by-NU part of this array contains the */
    /*             coefficient matrix A  of the reduced pencil. The remainder */
    /*                                 f */
    /*             of the leading (N+M)-by-(N+MIN(P,M)) part is used as */
    /*             internal workspace. */
    /*     LDAF    INTEGER */
    /*             The leading dimension of array AF.  LDAF >= MAX(1,N+M). */
    /*     BF      (output) COMPLEX*16 array, dimension (LDBF,N+M) */
    /*             The leading NU-by-NU part of this array contains the */
    /*             coefficient matrix B  of the reduced pencil. The */
    /*                                 f */
    /*             remainder of the leading (N+P)-by-(N+M) part is used as */
    /*             internal workspace. */
    /*     LDBF    INTEGER */
    /*             The leading dimension of array BF.  LDBF >= MAX(1,N+P). */
    /*     Tolerances */
    /*     TOL     DOUBLE PRECISION */
    /*             A tolerance used in rank decisions to determine the */
    /*             effective rank, which is defined as the order of the */
    /*             largest leading (or trailing) triangular submatrix in the */
    /*             QR (or RQ) factorization with column (or row) pivoting */
    /*             whose estimated condition number is less than 1/TOL. */
    /*             If the user sets TOL to be less than SQRT((N+P)*(N+M))*EPS */
    /*             then the tolerance is taken as SQRT((N+P)*(N+M))*EPS, */
    /*             where EPS is the machine precision (see LAPACK Library */
    /*             Routine DLAMCH). */
    /*     Workspace */
    /*     IWORK   INTEGER array, dimension (MAX(M,P)) */
    /*     DWORK   DOUBLE PRECISION array, dimension (MAX(N,2*MAX(P,M))) */
    /*     ZWORK   DOUBLE PRECISION array, dimension (LZWORK) */
    /*             On exit, if INFO = 0, ZWORK(1) returns the optimal value */
    /*             of LZWORK. */
    /*     LZWORK  INTEGER */
    /*             The length of the array ZWORK. */
    /*             LZWORK >= MAX( 1, MIN(P,M) + MAX(3*M-1,N), */
    /*                               MIN(P,N) + MAX(3*P-1,N+P,N+M), */
    /*                               MIN(M,N) + MAX(3*M-1,N+M) ). */
    /*             An upper bound is MAX(s,N) + MAX(3*s-1,N+s), with */
    /*             s = MAX(M,P). */
    /*             For optimum performance LZWORK should be larger. */
    /*             If LZWORK = -1, then a workspace query is assumed; */
    /*             the routine only calculates the optimal size of the */
    /*             ZWORK array, returns this value as the first entry of */
    /*             the ZWORK array, and no error message related to LZWORK */
    /*             is issued by XERBLA. */
    /*     Error Indicator */
    /*     INFO    INTEGER */
    /*             = 0:  successful exit; */
    /*             < 0:  if INFO = -i, the i-th argument had an illegal */
    /*                   value. */
    /*     METHOD */
    /*     The routine extracts from the system matrix of a state-space */
    /*     system (A,B,C,D) a regular pencil A - lambda*B  which has the */
    /*                                        f          f */
    /*     invariant zeros of the system as generalized eigenvalues as */
    /*     follows: */
    /*        (a) construct the (N+P)-by-(N+M) compound matrix (B  A); */
    /*                                                         (D  C) */
    /*        (b) reduce the above system to one with the same invariant */
    /*            zeros and with D of full row rank; */
    /*        (c) pertranspose the system; */
    /*        (d) reduce the system to one with the same invariant zeros and */
    /*            with D square invertible; */
    /*        (e) perform a unitary transformation on the columns of */
    /*            (A - lambda*I  B) in order to reduce it to */
    /*            (      C       D) */
    /*            (A  - lambda*B   X) */
    /*            ( f           f   ), with Y and B  square invertible; */
    /*            (     0          Y)              f */
    /*        (f) compute the right and left Kronecker indices of the system */
    /*            (A,B,C,D), which together with the orders of the infinite */
    /*            zeros (determined by steps (a) - (e)) constitute the */
    /*            complete set of structural invariants under strict */
    /*            equivalence transformations of a linear system. */
    /*     REFERENCES */
    /*     [1] Svaricek, F. */
    /*         Computation of the Structural Invariants of Linear */
    /*         Multivariable Systems with an Extended Version of */
    /*         the Program ZEROS. */
    /*         System & Control Letters, 6, pp. 261-266, 1985. */
    /*     [2] Emami-Naeini, A. and Van Dooren, P. */
    /*         Computation of Zeros of Linear Multivariable Systems. */
    /*         Automatica, 18, pp. 415-430, 1982. */
    /*     NUMERICAL ASPECTS */
    /*     The algorithm is backward stable (see [2] and [1]). */
    /*     FURTHER COMMENTS */
    /*     In order to compute the invariant zeros of the system explicitly, */
    /*     a call to this routine may be followed by a call to the LAPACK */
    /*     Library routine ZGGEV with A = A , B = B  and N = NU. */
    /*                                     f       f */
    /*     If RANK = 0, the routine ZGEEV can be used (since B = I). */
    /*                                                        f */
    /*     CONTRIBUTOR */
    /*     V. Sima, Katholieke Univ. Leuven, Belgium, Nov. 1996. */
    /*     Complex version: V. Sima, Research Institute for Informatics, */
    /*     Bucharest, Nov. 2008. */
    /*     REVISIONS */
    /*     V. Sima, Research Institute for Informatics, Bucharest, Mar. 2009, */
    /*     Apr. 2009. */
    /*     KEYWORDS */
    /*     Generalized eigenvalue problem, Kronecker indices, multivariable */
    /*     system, unitary transformation, structural invariant. */
    /*     ****************************************************************** */
    /*     .. Parameters .. */
    /*     .. Scalar Arguments .. */
    /*     .. Array Arguments .. */
    /*     .. Local Scalars .. */
    /*     .. External Functions .. */
    /*     .. External Subroutines .. */
    /*     .. Intrinsic Functions .. */
    /*     .. Executable Statements .. */
    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    b_dim1 = *ldb;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    c_dim1 = *ldc;
    c_offset = c_dim1 + 1;
    c__ -= c_offset;
    d_dim1 = *ldd;
    d_offset = d_dim1 + 1;
    d__ -= d_offset;
    --infz;
    --kronr;
    --kronl;
    af_dim1 = *ldaf;
    af_offset = af_dim1 + 1;
    af -= af_offset;
    bf_dim1 = *ldbf;
    bf_offset = bf_dim1 + 1;
    bf -= bf_offset;
    --iwork;
    --dwork;
    --zwork;
    /* Function Body */
    *info = 0;
    lequil = lsame_(equil, "S", 1L, 1L);
    lquery = *lzwork == -1;
    /*     Test the input scalar arguments. */
    if (! lequil && ! lsame_(equil, "N", 1L, 1L))
    {
        *info = -1;
    }
    else if (*n < 0)
    {
        *info = -2;
    }
    else if (*m < 0)
    {
        *info = -3;
    }
    else if (*p < 0)
    {
        *info = -4;
    }
    else if (*lda < max(1,*n))
    {
        *info = -6;
    }
    else if (*ldb < max(1,*n))
    {
        *info = -8;
    }
    else if (*ldc < max(1,*p))
    {
        *info = -10;
    }
    else if (*ldd < max(1,*p))
    {
        *info = -12;
    }
    else /* if(complicated condition) */
    {
        /* Computing MAX */
        i__1 = 1, i__2 = *n + *m;
        if (*ldaf < max(i__1,i__2))
        {
            *info = -22;
        }
        else /* if(complicated condition) */
        {
            /* Computing MAX */
            i__1 = 1, i__2 = *n + *p;
            if (*ldbf < max(i__1,i__2))
            {
                *info = -24;
            }
            else
            {
                ii = min(*p,*m);
                /* Computing MAX */
                /* Computing MAX */
                i__3 = *m * 3 - 1;
                /* Computing MAX */
                i__4 = *p * 3 - 1, i__5 = *n + *p, i__4 = max(i__4,i__5), i__5 = *n + *m;
                /* Computing MAX */
                i__6 = *m * 3 - 1, i__7 = *n + *m;
                i__1 = ii + max(i__3,*n), i__2 = min(*p,*n) + max(i__4,i__5), i__1 = max(i__1,i__2), i__2 = min(*m,*n) + max(i__6,i__7), i__1 = max(i__1,i__2);
                i__ = max(i__1,1);
                if (lquery)
                {
                    svlmax = 0.;
                    ninfz = 0;
                    ab8nxz_(n, m, p, p, &c__0, &svlmax, &bf[bf_offset], ldbf, &ninfz, &infz[1], &kronl[1], &mu, nu, nkrol, tol, &iwork[1], &dwork[1], &zwork[1], &c_n1, info);
                    /* Computing MAX */
                    i__1 = i__, i__2 = (integer) zwork[1].r;
                    wrkopt = max(i__1,i__2);
                    i__1 = *m - ii;
                    ab8nxz_(n, &ii, m, &i__1, &ii, &svlmax, &af[af_offset], ldaf, &ninfz, &infz[1], &kronl[1], &mu, nu, nkrol, tol, &iwork[1], &dwork[1], &zwork[1], &c_n1, info);
                    /* Computing MAX */
                    i__1 = wrkopt, i__2 = (integer) zwork[1].r;
                    wrkopt = max(i__1,i__2);
                    i__1 = *n + ii;
                    nb = ilaenv_(&c__1, "ZGERQF", " ", &ii, &i__1, &c_n1, &c_n1, 6L, 1L);
                    /* Computing MAX */
                    i__1 = wrkopt, i__2 = ii + ii * nb;
                    wrkopt = max(i__1,i__2);
                    /* Computing MIN */
                    i__3 = *n + ii;
                    i__1 = 64, i__2 = ilaenv_(&c__1, "ZUNMRQ", "RC", n, &i__3, &ii, &c_n1, 6L, 2L);
                    nb = min(i__1,i__2);
                    /* Computing MAX */
                    i__1 = wrkopt, i__2 = ii + *n * nb;
                    wrkopt = max(i__1,i__2);
                }
                else if (*lzwork < i__)
                {
                    *info = -29;
                }
            }
        }
    }
    if (*info != 0)
    {
        /*        Error return. */
        i__1 = -(*info);
        xerbla_("AB08NZ", &i__1, 6L);
        return 0;
    }
    else if (lquery)
    {
        zwork[1].r = (doublereal) wrkopt, zwork[1].i = 0.;
        return 0;
    }
    *dinfz = 0;
    *nkrol = 0;
    *nkror = 0;
    /*     Quick return if possible. */
    if (*n == 0)
    {
        if (min(*m,*p) == 0)
        {
            *nu = 0;
            *rank = 0;
            zwork[1].r = 1., zwork[1].i = 0.;
            return 0;
        }
    }
    mm = *m;
    nn = *n;
    pp = *p;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__)
    {
        infz[i__] = 0;
        /* L20: */
    }
    if (*m > 0)
    {
        i__1 = *n + 1;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            kronr[i__] = 0;
            /* L40: */
        }
    }
    if (*p > 0)
    {
        i__1 = *n + 1;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            kronl[i__] = 0;
            /* L60: */
        }
    }
    /*     (Note: Comments in the code beginning "CWorkspace:" and */
    /*     "RWorkspace:" describe the minimal amount of complex and real */
    /*     workspace, respectively, needed at that point in the code, as */
    /*     well as the preferred amount for good performance.) */
    wrkopt = 1;
    /*     Construct the compound matrix  ( B  A ), dimension (N+P)-by-(M+N). */
    /*                                    ( D  C ) */
    zlacpy_("Full", &nn, &mm, &b[b_offset], ldb, &bf[bf_offset], ldbf, 4L);
    if (pp > 0)
    {
        zlacpy_("Full", &pp, &mm, &d__[d_offset], ldd, &bf[nn + 1 + bf_dim1], ldbf, 4L);
    }
    if (nn > 0)
    {
        zlacpy_("Full", &nn, &nn, &a[a_offset], lda, &bf[(mm + 1) * bf_dim1 + 1], ldbf, 4L);
        if (pp > 0)
        {
            zlacpy_("Full", &pp, &nn, &c__[c_offset], ldc, &bf[nn + 1 + (mm + 1) * bf_dim1], ldbf, 4L);
        }
    }
    /*     If required, balance the compound matrix (default MAXRED). */
    /*     RWorkspace: need   N. */
    if (lequil && nn > 0 && pp > 0)
    {
        maxred = 0.;
        tb01iz_("A", &nn, &mm, &pp, &maxred, &bf[(mm + 1) * bf_dim1 + 1], ldbf, &bf[bf_offset], ldbf, &bf[nn + 1 + (mm + 1) * bf_dim1], ldbf, &dwork[1], info, 1L);
    }
    /*     If required, set tolerance. */
    thresh = sqrt((doublereal) ((*n + *p) * (*n + *m))) * dlamch_("Precision", 9L);
    toler = *tol;
    if (toler < thresh)
    {
        toler = thresh;
    }
    i__1 = nn + pp;
    i__2 = nn + mm;
    svlmax = zlange_("Frobenius", &i__1, &i__2, &bf[bf_offset], ldbf, &dwork[1], 9L);
    /*     Reduce this system to one with the same invariant zeros and with */
    /*     D upper triangular of full row rank MU (the normal rank of the */
    /*     original system). */
    /*     RWorkspace: need   2*MAX(M,P); */
    /*     CWorkspace: need   MAX( 1, MIN(P,M) + MAX(3*M-1,N), */
    /*                                MIN(P,N) + MAX(3*P-1,N+P,N+M) ); */
    /*                 prefer larger. */
    ro = pp;
    sigma = 0;
    ninfz = 0;
    ab8nxz_(&nn, &mm, &pp, &ro, &sigma, &svlmax, &bf[bf_offset], ldbf, &ninfz, &infz[1], &kronl[1], &mu, nu, nkrol, &toler, &iwork[1], &dwork[1], &zwork[1], lzwork, info);
    /* Computing MAX */
    i__1 = wrkopt, i__2 = (integer) zwork[1].r;
    wrkopt = max(i__1,i__2);
    *rank = mu;
    /*     Pertranspose the system. */
    numu = *nu + mu;
    if (numu != 0)
    {
        mnu = mm + *nu;
        numu1 = numu + 1;
        i__1 = numu;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            zcopy_(&mnu, &bf[i__ + bf_dim1], ldbf, &af[(numu1 - i__) * af_dim1 + 1], &c_n1);
            /* L80: */
        }
        if (mu != mm)
        {
            /*           Here MU < MM and MM > 0 (since MM = 0 implies MU = 0 = MM). */
            pp = mm;
            nn = *nu;
            mm = mu;
            /*           Reduce the system to one with the same invariant zeros and */
            /*           with D square invertible. */
            /*           RWorkspace: need   2*M. */
            /*           CWorkspace: need   MAX( 1, MU + MAX(3*MU-1,N), */
            /*                                   MIN(M,N) + MAX(3*M-1,N+M) ); */
            /*                       prefer larger. Note that MU <= MIN(M,P). */
            ro = pp - mm;
            sigma = mm;
            ab8nxz_(&nn, &mm, &pp, &ro, &sigma, &svlmax, &af[af_offset], ldaf, &ninfz, &infz[1], &kronr[1], &mu, nu, nkror, &toler, &iwork[1], &dwork[1], &zwork[1], lzwork, info);
            /* Computing MAX */
            i__1 = wrkopt, i__2 = (integer) zwork[1].r;
            wrkopt = max(i__1,i__2);
        }
        if (*nu != 0)
        {
            /*           Perform a unitary transformation on the columns of */
            /*                     ( B  A-lambda*I ) */
            /*                     ( D       C     ) */
            /*           in order to reduce it to */
            /*                     ( X  AF-lambda*BF ) */
            /*                     ( Y       0       ) */
            /*           with Y and BF square invertible. */
            zlaset_("Full", nu, &mu, &c_b1, &c_b1, &bf[bf_offset], ldbf, 4L);
            zlaset_("Full", nu, nu, &c_b1, &c_b2, &bf[(mu + 1) * bf_dim1 + 1], ldbf, 4L);
            if (*rank != 0)
            {
                nu1 = *nu + 1;
                i1 = *nu + mu;
                /*              CWorkspace: need   2*MIN(M,P); */
                /*                          prefer MIN(M,P) + MIN(M,P)*NB. */
                i__1 = *lzwork - mu;
                ztzrzf_(&mu, &i1, &af[nu1 + af_dim1], ldaf, &zwork[1], &zwork[mu + 1], &i__1, info);
                /* Computing MAX */
                i__3 = mu + 1;
                i__1 = wrkopt, i__2 = (integer) zwork[i__3].r + mu;
                wrkopt = max(i__1,i__2);
                /*              CWorkspace: need   MIN(M,P) + N; */
                /*                          prefer MIN(M,P) + N*NB. */
                i__1 = *lzwork - mu;
                zunmrz_("Right", "Conjugate transpose", nu, &i1, &mu, nu, &af[nu1 + af_dim1], ldaf, &zwork[1], &af[af_offset], ldaf, &zwork[mu + 1], &i__1, info, 5L, 19L);
                /* Computing MAX */
                i__3 = mu + 1;
                i__1 = wrkopt, i__2 = (integer) zwork[i__3].r + mu;
                wrkopt = max(i__1,i__2);
                i__1 = *lzwork - mu;
                zunmrz_("Right", "Conjugate transpose", nu, &i1, &mu, nu, &af[nu1 + af_dim1], ldaf, &zwork[1], &bf[bf_offset], ldbf, &zwork[mu + 1], &i__1, info, 5L, 19L);
            }
            /*           Move AF and BF in the first columns. This assumes that */
            /*           ZLACPY moves column by column. */
            zlacpy_("Full", nu, nu, &af[(mu + 1) * af_dim1 + 1], ldaf, &af[af_offset], ldaf, 4L);
            if (*rank != 0)
            {
                zlacpy_("Full", nu, nu, &bf[(mu + 1) * bf_dim1 + 1], ldbf, &bf[bf_offset], ldbf, 4L);
            }
        }
    }
    /*     Set right Kronecker indices (column indices). */
    if (*nkror > 0)
    {
        j = 1;
        i__1 = *n + 1;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            i__2 = j + kronr[i__] - 1;
            for (ii = j; ii <= i__2; ++ii)
            {
                iwork[ii] = i__ - 1;
                /* L100: */
            }
            j += kronr[i__];
            kronr[i__] = 0;
            /* L120: */
        }
        *nkror = j - 1;
        i__1 = *nkror;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            kronr[i__] = iwork[i__];
            /* L140: */
        }
    }
    /*     Set left Kronecker indices (row indices). */
    if (*nkrol > 0)
    {
        j = 1;
        i__1 = *n + 1;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            i__2 = j + kronl[i__] - 1;
            for (ii = j; ii <= i__2; ++ii)
            {
                iwork[ii] = i__ - 1;
                /* L160: */
            }
            j += kronl[i__];
            kronl[i__] = 0;
            /* L180: */
        }
        *nkrol = j - 1;
        i__1 = *nkrol;
        for (i__ = 1; i__ <= i__1; ++i__)
        {
            kronl[i__] = iwork[i__];
            /* L200: */
        }
    }
    if (*n > 0)
    {
        *dinfz = *n;
L220:
        if (infz[*dinfz] == 0)
        {
            --(*dinfz);
            if (*dinfz > 0)
            {
                goto L220;
            }
        }
    }
    zwork[1].r = (doublereal) wrkopt, zwork[1].i = 0.;
    return 0;
    /* *** Last line of AB08NZ *** */
} /* ab08nz_ */

