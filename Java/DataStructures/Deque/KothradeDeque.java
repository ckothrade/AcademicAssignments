/**
 * This program provides an implementation of the Deque interface
 * and demonstrates it.
 * 
 * @author (your name), Acuna
 * @version (version)
 */
import java.util.NoSuchElementException;
    
public class KothradeDeque<T> implements Deque<T> {
 
    private int count;
    private LinearDoubleNode<T> head, tail; //front, back

    /**
     * Creates an empty queue.
     */
    public KothradeDeque()
    {
        count = 0;
        head = tail = null;
    }
	
	@Override
	public void enqueueFront(T element)
    {
         LinearDoubleNode<T> node = new LinearDoubleNode<T>(element);
         if (head==null)
         {
            head = node;
            tail = head;
         }
         else
         {
            node.setNext(head);
            head = node;
         }

        count++;
    }
	
	@Override
	public void enqueueBack(T element)
    {
        LinearDoubleNode<T> node = new LinearDoubleNode<T>(element);

        if (tail == null)
        {
            tail = node;
            head = tail;
        }
        else
        {
            tail.setNext(node);
            tail = node;
        }
              
        count++;
    }
	
	@Override
	public T dequeueFront() throws NoSuchElementException
    {
        LinearDoubleNode<T> node = head;
        head = node.getNext();
        if(head == null)
            tail = null;
        count--;
        
        return node.getElement();
    }
    
	@Override
	public T dequeueBack() throws NoSuchElementException
    {
        T ele = tail.getElement();
        LinearDoubleNode<T> nods = head;
        LinearDoubleNode<T> nodt = head;
        while(nods != tail)
        {
            nodt = nods;
            nods = nods.getNext();
        }
        tail = nodt;
        tail.setNext(null);
        count--;
         
        return ele;
    }
	
	@Override
	public T first() throws NoSuchElementException
    {
        
        return head.getElement();
    }
	 
	@Override
	public T last() throws NoSuchElementException
    {
        return tail.getElement();
    }
	 
	@Override
    public boolean isEmpty()
    {
		if (count==0)
        	return true;
        else
        	return false;
    }
	 
	@Override
	public int size()
    {
        return count;
    }
	 
	@Override
	public String toString()
    {
        String result = "";
        LinearDoubleNode<T> current = head;
         
        while (current != null)
        {
            result = result + (current.getElement()).toString() + " ";
            current = current.getNext();
        }
         
        return result;
    }
} 