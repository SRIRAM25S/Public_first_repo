    #include <stdio.h>
    #include <math.h>
    int reversed(int n,int d);
    //method 1 for reverse using recursion
    // int rev(int n, int rev_num){
    //   if(n==0){
    //         return rev_num;
    //   }
    //   return rev(n/10, rev_num*10 + n%10);
    // }

    //for counting digits
    int count(int n){
        if(n<10){
            return 1;
        }
        return 1 + count(n/10);
    }
    // int count(int n){
    //     if(n==0)
    //         return 1;
    // int c = 0;
    // while (n != 0){
    //     c++;
    //     n /= 10;
    // }
    // return c;
    // }

    int power10(int exp){
    if(exp == 0)
        return 1;
    return 10 * power10(exp - 1);
}

    int rev(int n){
        int digits = count(n);
        return reversed(n,digits);
    }

    int reversed(int n, int digits){
        if(n==0)
            return 0;
        return (n % 10) * power10(digits - 1) + reversed(n / 10, digits - 1);
    }

    int main(){
        int n;
        scanf("%d", &n);

        printf("Number of digits: %d\n",count(n));
        printf("%d",rev(n));
        return 0;
    }

