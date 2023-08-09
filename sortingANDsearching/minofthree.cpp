class Solution{
  public:
    int middle(int A, int B, int C){
       if( (A>B || A >C ) && (A<C || A<B) ) return A;
       if((B > A || B > C ) && ( B < A || B<C )) return B;
       if( (C > A || C>B) && (C<A || C<B)) return C;

        /*  using array */
        int a[3] = {A, B, C};
        sort(a, a+3);
        return a[1];
    }
};