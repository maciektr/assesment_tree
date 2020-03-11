# Zadanie programistyczne OpenX

Wybrałem wariant pierwszy zadania. 

W celu optymalizacji wykonywanych operacji zastosowałem metodę memoryzacji. Po jednym wykonaniu zapytania dla danego węzła algorytm zapamiętuje (w haszmapie) wartości pozwalające wykonać tą operację dla wszystkich poddrzew w czasie stałym. W przypadku zastosowania w środowisku o ograniczonej pamięci operacyjnej konieczne byłoby dodanie mechanizmu usuwającego rzadko wykorzystywane wartości. W implementacji użyłem kontenera unordered_map z języka C++ (tablica haszująca), możliwe byłoby także użycie chociażby kontenera map (drzewo BST). 

Do obliczania mediany wykorzystałem algorytm rekurencyjny podobny do merge-sorta. Dzięki niemu uzyskuję odpowiedzi dla każdego z poddrzew od węzła od którego została wywołana operacja obliczenia mediany. Pozwala to potencjalnie przyśpieszyć podobne operacje w przyszłości. Rezygnacja z tego mechanizmu (memoryzacji) pozwoliłaby nam ograniczyć czas wykonania pojedynczej operacji obliczenia mediany (nie mielibyśmy wtedy jednak wyników dla poddrzew). Możliwe byłoby także zachowanie tego mechanizmu, ale z użyciem innej metody obliczenia mediany, np. opartej o dwa kopce binarne, lub drzewo BST (multiset w języku C++).

Rozwiązanie zostało również wyposażone w zestaw testów poprawnościowych zawartych w pliku "test.cpp" (w tym test randomizowany). Możliwe jest także ich uruchomienie przy pomocy polecenia "make test".