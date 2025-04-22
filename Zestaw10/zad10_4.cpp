
/*
4. Niektóre z tych algorytmów są nowe   
    std::for_each_n  
    std::exclusive_scan
    std::inclusive_scan  
    std::transform_exclusive_scan
    std::transform_inclusive_scan  
    std::parallel::reduce
    std::parallel::transform_reduce
ósmy algorytm std::for_each różni się i też uważamy go za nowy,
ponieważ oprócz dodatkowej polityki wykonywania teraz zwracanym typem jest void….
Przygotuj na podstawie dokumentacji (https://en.cppreference.com/w/cpp/experimental/parallelism)
przykłady wykorzystania tych algorytmów. W przypadku reduce wykorzystaj alfa expression
( [](auto fir, auto sec){ return fir + ":" + sec; }); )
do zdefiniowania BinaryOp w celu dodawania stringów.  
*/