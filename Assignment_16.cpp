#include<bits/stdc++.h>
using namespace std;
/*
<aside>
💡 **Question 1**

Given an array, for each element find the value of the nearest element to the right which is having a frequency greater than that of the current element. If there does not exist an answer for a position, then make the value ‘-1’.

</aside>
*/
void NFG(int a[], int n, int freq[])
{
 
    stack<int> s;
    s.push(0);
    int res[n] = { 0 };
    for (int i = 1; i < n; i++)
    {
 
        if (freq[a[s.top()]] > freq[a[i]])
            s.push(i);
        else {
 
            while ( !s.empty()
                   && freq[a[s.top()]] < freq[a[i]])
            {
 
                res[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
    }
 
    while (!s.empty()) {
        res[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}

/*
<aside>
💡 **Question 2**

Given a stack of integers, sort it in ascending order using another temporary stack.

</aside>
*/
stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;
 
    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();
        while (!tmpStack.empty() && tmpStack.top() < tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
 
    return tmpStack;
}

/*
<aside> 💡 **Question 3** Given a stack with **push()**, **pop()**, and **empty()** operations, The task is to delete the **middle** element ****of it without using any additional data structure. </aside>
*/
void deleteMid_util(stack<char>&s, int sizeOfStack, int current){
        if(current==sizeOfStack/2)
        {
            s.pop();
            return;
        }
        int x = s.top();
        s.pop();
        current+=1;
        deleteMid_util(s,sizeOfStack,current);
    
        s.push(x);
}
void deleteMid(stack<char>&s, int sizeOfStack)
{
    deleteMid_util(s,sizeOfStack,0);
}


/*
<aside>
💡 **Question 4**

Given a Queue consisting of first **n** natural numbers (in random order). The task is to check whether the given Queue elements can be arranged in increasing order in another Queue using a stack. The operation allowed are:

1. Push and pop elements from the stack
2. Pop (Or Dequeue) from the given Queue.
3. Push (Or Enqueue) in the another Queue.

**Examples :**

Input : Queue[] = { 5, 1, 2, 3, 4 } 

Output : Yes 

Pop the first element of the given Queue 

i.e 5. Push 5 into the stack. 

Now, pop all the elements of the given Queue and push them to second Queue. 

Now, pop element 5 in the stack and push it to the second Queue.   

Input : Queue[] = { 5, 1, 2, 6, 3, 4 } 

Output : No 

Push 5 to stack. 

Pop 1, 2 from given Queue and push it to another Queue. 

Pop 6 from given Queue and push to stack. 

Pop 3, 4 from given Queue and push to second Queue. 

Now, from using any of above operation, we cannot push 5 into the second Queue because it is below the 6 in the stack.

</aside>
*/

bool checkSorted(int n, queue<int>& q)
{
    stack<int> st;
    int expected = 1;
    int fnt;
    while (!q.empty()) {
        fnt = q.front();
        q.pop();
        if (fnt == expected)
            expected++;
 
        else {
    
            if (st.empty()) {
                st.push(fnt);
            }
            else if (!st.empty() && st.top() < fnt) {
                return false;
            }
            else
                st.push(fnt);
        }
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }
    }
    if (expected - 1 == n && st.empty())
        return true;
 
    return false;
}

/*
<aside>
💡 **Question 5**

Given a number , write a program to reverse this number using stack.

**Examples:**

</aside>
*/
stack <int> st;
void push_digits(int number)
{
    while (number != 0)
    {
        st.push(number % 10);
        number = number / 10;
    }
}
int reverse_number(int number)
{
    push_digits(number);
     
    int reverse = 0;
    int i = 1;
    while (!st.empty())
    {
        reverse = reverse + (st.top() * i);
        st.pop();
        i = i * 10;
    }
    return reverse;
}


/*
<aside>
💡 **Question 6**
Given an integer k and a **[queue](https://www.geeksforgeeks.org/queue-data-structure/)** of integers, The task is to reverse the order of the first **k** elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

- **enqueue(x) :** Add an item x to rear of queue
- **dequeue() :** Remove an item from front of queue
- **size() :** Returns number of elements in queue.
- **front() :** Finds front item.

</aside>
*/

void reverseQueueFirstKElements(int k, queue<int>& Queue)
{
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;
 
    stack<int> Stack;
    for (int i = 0; i < k; i++) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
    for (int i = 0; i < Queue.size() - k; i++) {
        Queue.push(Queue.front());
        Queue.pop();
    }
}
 

/*
<aside>
💡 **Question 7**

Given a sequence of n strings, the task is to check if any two similar words come together and then destroy each other then print the number of words left in the sequence after this pairwise destruction.

**Examples:**

Input : ab aa aa bcd ab

Output : 3

*As aa, aa destroys each other so,*

*ab bcd ab is the new sequence.*

Input :  tom jerry jerry tom

Output : 0

*As first both jerry will destroy each other.*

*Then sequence will be tom, tom they will also destroy*

*each other. So, the final sequence doesn’t contain any*

*word.*

</aside>
*/ 

int removeConsecutiveSame(vector <string > v)
{
    int n = v.size();
    for (int i=0; i<n-1; )
    {
        if (v[i].compare(v[i+1]) == 0)
        {
            v.erase(v.begin()+i);
            v.erase(v.begin()+i);
            if (i > 0)
                i--;
            n = n-2;
        }
        else
            i++;
    }
    return v.size();
}

/*
<aside>
💡 **Question 8**

Given an array of integers, the task is to find the maximum absolute difference between the nearest left and the right smaller element of every element in the array.

**Note:** If there is no smaller element on right side or left side of any element then we take zero as the smaller element. For example for the leftmost element, the nearest smaller element on the left side is considered as 0. Similarly, for rightmost elements, the smaller element on the right side is considered as 0.

</aside>
*/

void leftSmaller(int arr[], int n, int SE[])
{
    stack<int>S;
 
    for (int i=0; i<n; i++)
    {
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
        if (!S.empty())
            SE[i] = S.top();
        else
            SE[i] = 0;
        S.push(arr[i]);
    }
}
int findMaxDiff(int arr[], int n)
{
    int LS[n]; 
 
    leftSmaller(arr, n, LS);
    int RRS[n]; 
    reverse(arr, arr + n);
    leftSmaller(arr, n, RRS);
    int result = -1;
    for (int i=0 ; i< n ; i++)
        result = max(result, abs(LS[i] - RRS[n-1-i]));
    return result;
}
 