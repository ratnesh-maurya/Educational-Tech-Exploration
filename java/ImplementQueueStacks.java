import java.util.*;
public class ImplementQueueStacks {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    public ImplementQueueStacks() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    private void transfer(Stack<Integer> sender, Stack<Integer> receiver) {
        while (!sender.isEmpty()) {
            receiver.push(sender.pop());
        }
    }
    
    public void push(int x) {
        stack1.push(x);
    }
    
    public int pop() {
        transfer(stack1, stack2);
        int poppedVal = stack2.pop();
        transfer(stack2, stack1);
        return poppedVal;
    }
    
    public int peek() {
        transfer(stack1, stack2);
        int topVal = stack2.peek();
        transfer(stack2, stack1);       
        return topVal;
    }
    
    public boolean empty() {
        return stack1.isEmpty();
    }

}