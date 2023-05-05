#include "BinNode.h" //����������ڵ���
template <typename T> class BinTree { //������ģ����
protected:
  
public:
	int _size; BinNodePosi(T) _root; //��ģ�����ڵ�
    //virtual int updateHeight( BinNodePosi(T) x ); //���½ڵ�x�ĸ߶�
    //void updateHeightAbove( BinNodePosi(T) x ); //���½ڵ�x�������ȵĸ߶�
   
   BinTree()    //���캯��
   {
		_size = 0;
		//T temp;
   		//_root -> data = temp;
   }
   
   //~BinTree() { if ( 0 < _size ) remove( _root ); } //��������
   int size() const { return _size; } //��ģ
   bool empty() const { return !_root; } //�п�
   BinNodePosi(T) root() const { return _root; } //���� 
   BinNodePosi(T) insertAsRoot( T const& e); //������ڵ�  
   BinNodePosi(T) insertAsLC( T const& e, BinNodePosi(T) x); //�������� 
   BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e); //�����Һ��� 
   
   // �ص�   
   BinNodePosi(T) attachAsLC(BinNodePosi(T) x ,BinTree<T>* & S) //���������� 
   {
   		if(x -> lc == S -> root) x -> lc -> parent = x;
   		_size += S -> _size; updateHeightAbove(x);
   		S -> _root = NULL; S -> _size = 0;
//		    delete(S); 
			S = NULL; 
		   return x;
   }
   BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* & S) //���������� 
   {
   		if(x -> rc == S -> root) x -> rc -> parent = x;
   		_size += S -> _size; 
		   //updateHeightAbove(x);
   		S -> _root = NULL; S -> _size = 0; release(S); S = NULL; return x;
   }
   
   int remove ( BinNodePosi(T) x) //����ɾ��
   {
   		FromParentTo( *x ) = NULL;
   		//updateHeightAbove(x -> parent);
   		int n = removeAt(x); _size = n;
   		return n;
   }
   int removeAt(BinNodePosi(T) x){
   	if(!x) return 0;
   	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
    //  delete(x->data); delete(x); 
	return n;
   }
   BinTree<T>* secede ( BinNodePosi(T) ); //��������
   
   
   
   template <typename VST> //������
   void travLevel( VST& visit ) { if ( _root ) _root->travLevel( visit ); } //��α���
   template <typename VST> //������
   void travPre( VST& visit ) { if ( _root ) _root->travPre( visit ); } //�������
   template <typename VST> //������
   void travIn( VST& visit ) { if ( _root ) _root->travIn( visit ); } //�������
   template <typename VST> //������
   void travPost( VST& visit ) { if ( _root ) _root->travPost( visit ); } //�������
   bool operator<( BinTree<T> const& t ) //�Ƚ������������в��䣩
      { return _root && t._root && lt( _root, t._root ); }
   bool operator==( BinTree<T> const& t ) //�е���
      { return _root && t._root && ( _root == t._root ); }
}; //BinTree
