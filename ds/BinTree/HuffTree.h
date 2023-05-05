#include "BinNode.h" //����������ڵ���
template <typename T> class HuffTree { //������ģ����
public:
	int _size; BinNodePosi(T) _root; //��ģ�����ڵ� 
	
   HuffTree()    //���캯��  
   {
		_size = 0; 
		_root -> data = NULL; 
   }
   int size() const { return _size; } //��ģ 
   bool empty() const { return !_root; } //�п� 
   BinNodePosi(T) root() const { return _root; } //����  
   BinNodePosi(T) insertAsRoot( T const& e); //������ڵ�  
   BinNodePosi(T) insertAsLC( T const& e, BinNodePosi(T) x); //�������� 
   BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e); //�����Һ��� 
   
   // �ص�   
   BinNodePosi(T) attachAsLC(BinNodePosi(T) x ,HuffTree<T>* & S) //���������� 
   {
   		if(x -> lc == S -> root) x -> lc -> parent = x; 
   		_size += S -> _size; updateHeightAbove(x); 
   		S -> _root = NULL; S -> _size = 0; 
//		    delete(S); 
			S = NULL; 
		   return x; 
   }
   BinNodePosi(T) attachAsRC(BinNodePosi(T) x, HuffTree<T>* & S) //���������� 
   {
   		if(x -> rc == S -> root) x -> rc -> parent = x;
   		_size += S -> _size; 
   		S -> _root = NULL; S -> _size = 0; release(S); S = NULL; return x;
   }
   
   int remove ( BinNodePosi(T) x) //����ɾ��
   {
   		FromParentTo( *x ) = NULL;
   		int n = removeAt(x); _size = n;
   		return n;
   }
   int removeAt(BinNodePosi(T) x){
   	if(!x) return 0;
   	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //  delete(x->data); delete(x); 
	return n;
   }
   HuffTree<T>* secede ( BinNodePosi(T) ); //��������  
   
   bool operator<( HuffTree<T> const& t ) //�Ƚ������������в��䣩
      { return _root && t._root && lt( _root, t._root ); }
   bool operator==( HuffTree<T> const& t ) //�е���  
      { return _root && t._root && ( _root == t._root ); }
}; //BinTree
