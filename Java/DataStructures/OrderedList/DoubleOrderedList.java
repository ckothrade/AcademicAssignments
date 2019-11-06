
public class DoubleOrderedList <T> extends DoubleList<T> implements OrderedListADT<T> {

	/**
	 * Constructor.
	 */
	public DoubleOrderedList(){
		super();
	}
	
	/**
	 * Adds the element in the proper spot in the list.
	 */
	public void add(T element){
		Comparable<T> temp;      
		if(element instanceof Comparable)
			temp = (Comparable) element;
		else
			throw new NonComparableElementException ("Double Ordered List");
		
		DoubleNode<T> traverse = head;
		DoubleNode<T> newnode = new DoubleNode<> (element);
		
		if(isEmpty()){
			head = newnode;
			tail = newnode;
		}else if(temp.compareTo(tail.getElement()) >= 0){
			tail.setNext(newnode);
			newnode.setPrev(tail);
			newnode.setNext(null);
			tail = newnode;
		}else if(temp.compareTo(head.getElement()) <= 0){
			head.setPrev(newnode);
			newnode.setNext(head);;
			newnode.setPrev(null);
			head = newnode;
		}else{
			while((temp.compareTo(traverse.getElement()) > 0))
				traverse = traverse.getNext();   //this was all added by you
			newnode.setPrev(traverse.getPrev());
			newnode.setNext(traverse);
			traverse = traverse.getPrev();
			traverse.setNext(newnode);
			traverse = newnode.getNext();
			traverse.setPrev(newnode);
		
		}
		count++;
		
	}
}
