//---------------------------------------------------------------------------------------

/*
Description: next greater element

alternate questions: Stock span/next smaller element or last greater element
Steps:
1. traverse from left to right in array
2. a. pop, b. print, c. push
	a. pop all the elements less than the ith value
	b. print the peek value or -1 if stack gets empty
	c. push the ith value to the stack. 

Inputs:
5
5
3
8
-2
7

Ouputs:
8
8
-1
7
-1


*/

//Solution:
//code
public static int[] solve(int[] arr){
   // solve
   int[] res = new int[arr.length];
   if(arr.length==0)
        return res;
        
    
   Stack<Integer> st = new Stack<>();
   int i=arr.length-1;
   res[i] = -1;
   st.push(arr[i]);
   i--;
   for(;i>=0;i--) {
       if(st.size()==0) {
           //no greater element exists
           res[i] = -1;
       }
       else {
           while(st.size()>0 && st.peek() < arr[i]) {
               st.pop();
           }
           
           if(st.size()==0) {
               res[i] = -1;
           }
           else {
               res[i] = st.peek();   //peek n store in result arr
           }
       }
       
       st.push(arr[i]);
   }
   
   return res;
 }

//---------------------------------------------------------------------------------------

/*
Description: Duplicate brackets
You are required to print true if you detect extra brackets and false otherwise.

Steps:
While popping if u get the '(' directly then its a duplicate bracket else its not

Inputs:
((a + b) + (c + d)) -> false
(a + b) + ((c + d)) -> true

*/

//Solution:
//code
public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Stack<Character> st = new Stack<>();
        for(int i=0;i<str.length();i++) {
            char c= str.charAt(i);
            if(c==')') {
                if(st.peek()=='('){
                    System.out.println(true);
                    return;
                }
                else {
                    while(st.peek()!='(') {
                        st.pop();
                    }
                    st.pop();
                }
            }
            else {
                st.push(c);
            }
        }
        
        System.out.println(false);
    }

//---------------------------------------------------------------------------------------

/*
Description: Prefix evaluation
Steps:
while popping the a,b values from the stack interchange the way you pop the value.
Prefix expression: 1. sequence: a, b, 2. for loop right->left
Postfix expression: 1. sequence: b, a 2. for loop left->right

Inputs:
prefix

 -+2/*6483

Ouputs:

infix
postfix
eval

2
((2+((6*4)/8))-3)
264*8/+3-

*/

//Solution:
//code
public class Main{
  public static int evalIt(char op, int a, int b) {
      if(op=='+') {
        return a+b;
      }
      else if(op=='-') {
        return a-b;
      }
      else if(op=='*') {
        return a*b;
      }
      else if(op=='/') {
          return a/b;
      }
      
      return -1;    //invalid operator
  }
  
public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String exp = br.readLine();

    // code
    Stack<String> inf = new Stack<>();
    Stack<String> postf = new Stack<>();
    Stack<Integer> eval = new Stack<>();
    
    String a="",b="";
    int a1=0,b1=0;
    
    for(int i=exp.length()-1;i>=0;i--) {
        char c = exp.charAt(i);
        if(Character.isDigit(c)) {
            eval.push(c-'0');
            inf.push(c+"");
            postf.push(c+"");
        }
        else {
            a1 = eval.pop();b1 = eval.pop();
            eval.push(evalIt(c, a1, b1));
            
            a = inf.pop(); b = inf.pop();
            inf.push("(" + a+c+b + ")");
            
            a = postf.pop(); b = postf.pop();
            postf.push(a+b+c+"");
        }
    }
    
    System.out.println(eval.pop());
    System.out.println(inf.pop());
    System.out.println(postf.pop());
 }



