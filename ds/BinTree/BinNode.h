#include<iostream>
#include<algorithm>
#define BinNodePosi(T) BinNode<T>* 
#define stature(p) ((p) ? (p)->height : -1) 

/******************************************************************************************
 * BinNode״̬�����ʵ��ж� 
 ******************************************************************************************/
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //����ӵ��һ������
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //ͬʱӵ����������
#define IsLeaf(x) ( ! HasChild(x) )

/******************************************************************************************
 * ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
 ******************************************************************************************/
#define sibling( p ) ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc ) /*�ֵ�*/
#define uncle( x ) ( sibling( (x)->parent ) ) /*����*/
#define FromParentTo( x ) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )

template <typename T> struct BinNode { //�������ڵ�ģ���� 
public:
   T data; //��ֵ 
   BinNodePosi(T) parent;BinNodePosi(T) lc;BinNodePosi(T) rc; //���ڵ㼰���Һ���  
   int height; //�߶ȣ�ͨ�ã� 
   int npl; //Null Path Length����ʽ�ѣ�Ҳ��ֱ���� height���棩 
// ���캯��  
   BinNode() : data(NULL), parent( NULL ), lc( NULL ), rc( NULL ), height( 0 ), npl( 1 ){}
   BinNode( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL,
            BinNodePosi(T)  rc = NULL, int h = 0, int l = 1)
      : data( e ), parent( p ), lc( lc ), rc( rc ), height( h ), npl( l ) {}
// �����ӿ�
   int size(); //ͳ�Ƶ�ǰ�ڵ����������༴����Ϊ���������Ĺ�ģ
   BinNodePosi(T) insertAsLC( T const& e)
   {
   		return lc = new BinNode (e, this);
   } //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
   BinNodePosi(T) insertAsRC( T const& e)
   {
   		return rc = new BinNode (e, this); 
   } //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
   BinNodePosi(T) succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��
   template <typename VST> void travLevel( VST& ); //������α���
   template <typename VST> void travPre( VST& ); //�����������
   template <typename VST> void travIn( VST& ); //�����������
   template <typename VST> void travPost( VST& ); //�����������
// �Ƚ������е�����������һ���������в��䣩
   bool operator< ( BinNode const& bn ) { return data < bn.data; } //С��
   bool operator== ( BinNode const& bn ) { return data == bn.data; } //����
};
