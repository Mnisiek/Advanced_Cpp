
/*
4. Wykorzystując prywatne dziedziczenie wykonaj modyfikację i przenieś zmienną
_rep (dane ze stosu) z klasy Stack do klasy wytycznej, która dokonuje alokacji.
Zmodyfikuj odpowiednio klasę Stack.
*/

template<typename T = int , size_t N = 100,
	 typename Checking_policy = No_checking_policy,  
         template<typename U,size_t M>  class Allocator_policy 
	 = Static_table_allocator > 
class Stack: private Checking_policy, public Allocator_policy<T,N> {

  typedef typename Allocator_policy<T,N>::rep_type rep_type;

  size_t _top;

public:
  Stack(size_t n = N):_top(0) {
    Stack::init(n);
  };

  void push(const T &val) {
    Stack::expand_if_needed(_top);
    Checking_policy::check_push(_top,this->size());
    Stack::_rep[_top++]=val;
  }

  void pop()              {
    Checking_policy::check_pop(_top);
    --_top;
    Stack::shrink_if_needed(_top);
  }
  
  const T& top()  const   {
    Checking_policy::check_top(_top);
    return Stack::_rep[top-1];
  }
  
  bool is_empty()         {
    return !_top;
  } 

  ~Stack() {Stack::dealocate();}

};

main() {

  Stack<int,n,Std_exception_on_error_policy,Dynamic_table_allocator > s(n);

  //s.pop();

  for(int i = 0;i<n;++i)
    s.push(i);

  s.resize(20);
  std::cerr<<"last straw"<<std::endl;
  s.push(0);

  while(1)
    s.pop();
}