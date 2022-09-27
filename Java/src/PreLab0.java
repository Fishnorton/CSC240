public class PreLab0 {
    
    public static void main(String[] args) {
        // exampleMethod(5);
        // recursionExample(5);
        //descending(5);
        //System.out.println("5^3 = " + exponents(5, 3));
        // arithmeticSeries(4, 3, 3);

        // int[] nums1 = {1, 2, 20};
        // int[] nums2 = {1, 2, 3};
        // int[] nums3 = {3};
        // int[] nums4 = {1, 10, 3};

        // System.out.println(findIfElementIsFollowedBy10TimesIteself(nums1));
        // System.out.println(findIfElementIsFollowedBy10TimesIteself(nums2));
        // System.out.println(findIfElementIsFollowedBy10TimesIteself(nums3));
        // System.out.println(findIfElementIsFollowedBy10TimesIteself(nums4));
        // System.out.println("(0,0) " + findQuad(0,0));
        // System.out.println("(1,1) " + findQuad(1,1));
        // System.out.println("(0,1) " + findQuad(0,1));
        // System.out.println("(-1,1) " + findQuad(-1,1));
        // System.out.println("(-1,0) " + findQuad(-1,0));
        // System.out.println("(-1,-1) " + findQuad(-1, -1));
        // System.out.println("(0,-1) " + findQuad(0, -1));
        // System.out.println("(1,-1) " + findQuad(1, -1));
        // System.out.println("(1,0) " + findQuad(1, 0));

        System.out.println(diff(10));

    }
    public static void exampleMethod(Integer n) {
        System.out.println(n);
    }

    public static void recursionExample(Integer n) {
        if (n > 0) {
            System.out.println(n);
            recursionExample(n-1);
            System.out.println(n);
        } else {
            return;
        }
    }

    //Recursive method that takes in a positive integer input and decriments it by 1 until the last number is 1
    public static void descending (int n) {
        if (n == 0) {
            return; //base case
        } else {
            System.out.print(n + "   ");
            descending(n-1);
        }
    }

    //calculates value given and positive integer & base 
    public static int exponents(int base, int ex) {
        if(ex == 1) {
            return base;
        } else {
            return base * exponents(base, ex-1);
        }
    }

    //Works with palendromes (kayak and racecar)
    // public static boolean p(String s, int i, int f) {
    //     if (i < f) {
    //         if (s[i] == s[f]) {
    //             return p(s, i+1, f-1);
    //         } else {
    //             return false;
    //         }
    //     } else {
    //         return true;
    //     }
    // }

    
    //Recursion class practice 
    //Find the n'th number int the sequence

    public static int arithmeticSeries(int initValue, int delta, int n) {
        if(n == 1) {
            return initValue;
        } else {
            return arithmeticSeries(initValue + delta, delta, n-1);
        }
    }

    //Given an array of ints, compute if somewhere in the array, there is an instance where a value is followed by a value 10 times itself
    public static boolean findIfElementIsFollowedBy10TimesIteself(int[] arr) {
        if(arr.length <= 1) {
            return false; //No enough data
        } else {
            return foundTimes10Helper(arr, 0); //Initalize index = 0
        }
    }

    public static boolean foundTimes10Helper(int[] arr, int index) {
        if(index == arr.length-1) {
            return false;
        } else if ((arr[index] * 10) == arr[index+1]){
            return true;
        } else {
            return foundTimes10Helper(arr, index+1);
        }
    }

    public static String findQuad(int x, int y) {
        if (x == 0) {
            if (y == 0) {
                return "Origin";
            } else {
                return "Y-axis";
            }
        } else {
            if (x > 0) {
                //Check q1,4
                if(y == 0) {
                    return "X-axis";
                } else {
                    if (y > 0) {
                        return "Q1";
                    } else {
                        return "Q4";
                    }
                }
            } else {
                //Check q2,3
                if(y == 0) {
                    return "X-axis";
                } else {
                    if (y > 0) {
                        return "Q2";
                    } else {
                        return "Q3";
                    }
                }
            }
        }
    }

    public static int diff(int N) {
        return (SqOfSum(N)*SqOfSum(N)) - SumOfSq(N);
    }

    public static int SqOfSum(int N) {
        if (N != 0) {
            return N + SqOfSum(N-1);
        } else {
            return N;
        }
    }

    public static int SumOfSq(int N) {
        if (N == 0) { //Base Case
            return 0;
        } else {
            return SumOfSq(N-1) + N*N;
        }
    }
}
