
public class DoubleList <T> implements ListADT <T>{

	
	protected int count;
	protected DoubleNode<T> head, tail;
	

	/**
	 * Constructor.
	 */
	public DoubleList(){
		count = 0;
		head = tail = null;
	}
	
	/**
	 * Removes the first element in the list.
	 * @return Element removed
	 */
	@Override
	public T removeFirst(){
		T element;
		
		if (isEmpty())
			throw new EmptyCollectionException("Linked List");
		
		if (head == tail){
			element = head.getElement();
			head = null;
			tail = null;	
		}else{
			element = head.getElement();
			head = head.getNext();
		}
		
		count--;
		return element;
	}
	
	/**
	 * Removes the last element in the list.
	 * @return Element removed
	 */
	@Override
	public T removeLast(){
		T element;
		
		if (isEmpty())
			throw new EmptyCollectionException("Linked List");
		
		if (head == tail){
			element = head.getElement();
			head = null;
			tail = null;	
		}else{
			element = tail.getElement();
			tail = tail.getPrev();
			//check here
			tail.setNext(null);
		}
		
		count--;
		
		return element;
	}
	
	/**
	 * Removes the specified element.
	 * @return Element removed
	 */
	@Override
	public T remove(T targetElement){
		
		if (isEmpty())
			throw new EmptyCollectionException("Linked List");
		
		boolean found = false;
		DoubleNode<T> previous = null;
		DoubleNode<T> current = head;
		DoubleNode<T> temp = null;
		
		while(current != null && !found)
			if(targetElement.equals(current.getElement()))
				found = true;
			else{
				previous = current;
				current = current.getNext();
			}
				
		if(!found)
			throw new ElementNotFoundException("Linked List");
		
		if(size() == 1)
			head = tail = null;
		else if(current.equals(head))
			head = current.getNext();
		else if(current.equals(tail)){
			tail = previous;
			tail.setNext(null);
		}else{
			previous.setNext(current.getNext());
			temp = current.getNext();
			temp.setPrev(current.getPrev());
		}  
		
		count--;
		//modCount++
		
		return current.getElement();
	}
	
	/**
	 * Grabs the first element in the list.
	 * @return First Element
	 */
	@Override
	public T first(){
		if(isEmpty())
			throw new EmptyCollectionException("Linked List");
		
		return head.getElement();
	}
	
	/**
	 * Grabs the last element in the list.
	 * @return Last Element
	 */
	@Override
	public T last(){
		if(isEmpty())
			throw new EmptyCollectionException("Linked List");
		
		return tail.getElement();
	}
	
	/**
	 * Checks to see if the element is in the list.
	 * @return True if the element is in the list
	 */
	@Override
	public boolean contains(T target){
		
		boolean found = false;
		
		DoubleNode <T> current = head;
		while(current != null && !found)
			if(target.equals(current.getElement()))
				found = true;
			else{
				current = current.getNext();
			}
		
		return found;
	}
	
	/**
	 * Check to see if the list is empty.
	 * @return True if the list is empty
	 */
	@Override
	public boolean isEmpty(){
		if(count == 0)
			return true;
		else
			return false;
	}
	/**
	 * Returns size of the Linked List.
	 * @return size
	 */
	@Override
	public int size(){
		return count;
	}

	/**
	 * Displays the contents of the list.
	 * @return contents
	 */
	@Override
	public String toString(){
		String temp = "";
		DoubleNode<T> current = head;
		
		while (current != null){
			temp += " " + current.getElement();
			current = current.getNext();
		}
		
		return temp;
	}
	
}
