# STL Benchmarks - Report

##Pkt 1.
**1)How to define correct less-than operator? What should it do for N-dimensional data such as our table?**
Poprawnie zaimplementowany operator przechodzi po po obu zbiorach danych i porównuje czy dane o tym samym indeksie
sa różne od siebie, jeśli tak to sprawdza ktory jest mniejszy i w zależności od tego zwraca wynik.
**2)What is the optimal implementation for equality operator for continuous block of data?**
Opeartor ten przechodzi po obu zbiorach danych i porownuje dane o tym samym indeksie.
**3)What is the purpose of hash function? What are its mathematical properties?**
Celem funkcji hashujacek jest zmniejszenie czasu wyszukiwania wartosci w pewnej bazie danych. 
**4)Describe/justify your implementation.**
a) operatory mniejszości, równości oraz funkcja hashująca dla typu Small są błache.
b) oprator mniejszości dla typu Medium przechodzi po tablicach obu obietków i sprawdza czy dane komórki 
danych są róźne, jeśli tylko na takie natrafi to znaczy że trzeba sprawidzć która jest mniejsza i 
 w zależności od wyniku zwraca wartość logiczną True lub False. Operator równości działa bardzo podobnie,
 jak tylko natrafi na dwie różne wartości to zwraca wartość False. W funkcji hashującej natomiast skorzystałem
 z wbudowanej funkcji std::hash, przechodzę po całym bloku danych i dodaję wartości zwrócone przez funkcję std::hash.
 c) implementacja wyżej wymienionych operatorów i funkcji dla typu Large jest identyczna jak dla typu Small.
##Pkt 2.
**1)How did you test correctness of operator <, == and hash function**
Poprawność działania funkcji sprawdziłem poprzez zadeklarowanie obiektów typów Small, Medium oraz Large, 
przez wartości mi znane co pozwoliło na dokładną weryfikację poprawności działania operatorów oraz
funkcji hashującej.
**2)Should we initialize tested objects (Small/Medium/Large) with random data? Or should we initialize them manually with known data?**
Powinniśmy uzupełniać obiekty testowe manualnie, pozwala to na bardziej przewidywalne, oraz dokładne testy.
##Pkt 3.
**1) Describe structure of benchmark that measures computational complexity (Big O)**
Standardowy benchmark składa się z pętli benchmarka i w naszym przypadku, deklaracji
badanych kontenerów, w pętli benachmarku badana jest funkcja lub zbiór funkcji, wywoływanych 
dla zdeklarowanego kontenera lub kontenerów.
**2) Are there any consequences for sequential containers when our implementation is slow?**
Kontenery sekwencyjne są mniej podatne na wadliwe implementacje ze względu na to że można do nich dodawać dane
nie przejmując się czy takie dane się już w danym kontenrze znajdują. 
**3) What is the impact of slow operator less-than implementation on sorted associative containers?**
Zla implementacja operatora mniejszości może zdecydowanie opóznic dodawanie, usuawanie i podobne operacje które albo
modyfikują kontener albo czegoś w nim szukają, ze względu na zły operator, funkcja może potrzebować więcej czasu a nawet zwrócić zly wynik.
**4)What is the impact of slow equality operator / hash function on unordered associative containers?**
Tego typu kontenery opierają się na funkcjach hashujacych podaczas większości operacji, przez co powolna
implementacja takiej funkcji może znacząco wydłużyć wszelkie operacje wykonywane na tej strukturze danych.
**5) Describe your benchmark results.**
Są to pojedyncze czasy dla kontretnych operatorów pozwalające zobaczyć ile srednio może się wykonywać
dana operacja.
**6)Should we initialize objects (Small/Medium/Large) with random data? Why? Why not?**
Obiekty tworzone na potrzeby benchmarku powinny być incjalizowane losowymi danymi,
pomaga to na zbadanie bardziej ogólnej wydajności niż w przypadku ręcznej inicjalizacji.
##Pkt 4.
**1)Describe structure of benchmark that measures computational complexity (Big O)**
Na początku zdefiniowane rozmiaru kontenera, petla benchmarku, iterująca po różnych rozmiarach danego kontenera,
oraz wykonująca bane przez nas operacje. Następnie deklaracja funkcji do pomiaru złożoności obliczeniowej.
Na końcu Bechmark wywoływany w odpowedni zakresie rozmiaru dla, oraz wywołaniem funkcji mierzącej złożoność
obliczeniową.
**2)Plot benchmarks results on graphs with your complexity result**
Wykresy dla przypisanych mi kontenerów znajdują się kolejno w:
/output/vectorBenchmarks
/output/multimapBenchmark
/output/unorderedMultimapBenchmarks
**3)Did you get the same complexity as e.g. on cppreference.com. If not why are they different?**
Udało się uzyskać takie same złożoności obliczeniowe jak na stronie cppreference.com, jedynie
w niektórych przypadkach, złożoność obliczeniowa była taka jak w najgorszym scenariuszu dla
konkretnej funkcji.
**4)How can we write benchmarks for methods that e.g.: add or remove elements from collection? Describe Pause/Resume timing method. Describe baseline method. How did you implement those benchmarks?**
W moim rozwiązaniu jest użyte następujące rozwiązanie dla takich funkcji: 
przed pętlą benchmarka jest inicjalizowany kontener i wypełniany jest losowymi wartościami, następnie w 
pętli benchmarka jest wywoływana funkcja insert a następnie erase. Jesli funkcje modyfikują kontener i nie da się go przywrocić do stanu 
sprzed modyfikacji, inicjalizacja i wypełnanie kontenera wartościami odbywa się w pętli benchmarku, co wymaga
utworzenia osobnych benchmarków dla inicjalizacji i wypełnienia wartościami kontenera aby móc dokładnie zbadać 
czas wykonywania się badanej funkcji.
Metoda Pause/Resume, pozwala na zatrzymanie mierzenia czas wykonywania się benchamrku co pozwala np na jego inicjalizacje i wypełenieni danymi 
bezpośrednio w pętli benchmarku, a mierzenie czasu jedynie funkcji przez nas porządanej. Wadą tego rozwiązania jest jednak
duży czas wykonywania się funkcji Pause/Resume, co nie tylko wydłuża czas wykonania się benchamarku, ale również może 
spowodować niedokładne obliczenie czasu wykonywania się danej funkcji. 
W moim rozwiązanu użyłem metody baseline, gdzie funkcje które musiały się pojawić w pętli benchmarku 
ale nie były przez na stricte badane, miały swoje osobne benchmarki, aby po odjęciu czasu ich wykonywania uzyskać czas
badanej funkcji. 
##Pkt 5.
**1) Why does the compiler optimizer break our benchmark code?**
Ponieważ jeśli wyniki badanych przez nas funkcji nie są nigdzie wykorzystywane, to kompilator uważa ich wywołanie jako zbędne
przez co je "omija" i badany przez nas czas znacząco się skraca.
**2)What do the DoNotOptimze(...) and ClobberMemory() helpers do?**
Funkcje te zapobiegają optymalizacji kodu przez kompilator, nawet jesli wyniki funkcji nie są wykorzystywane,
co pozwala na wiarygodne zbadanie czasu wykonania się danej funkcji.
**3)Plot benchmarks results for both Debug and Release mode? Did you see any changes in times/complexity?**
Zdecydowanie mniejsze czasy uzyskiwane były dla typu Release, natomiast złożoność obliczeniowa pozostawała bez zmian.
##Pkt 6.
**1) Plot benchmarks results for all types Small/Medium/Large and Debug/Release mode on single graph (if possible, 6 lines). Did you see any changes in times/complexity?**
Zdecydowanie duża różnica jest zauważalna w czasie wykonywania się benchmarków, w niektórych przypadkach zmieniała się również złożoność ale
w granicach toleracji dla danej funkcji. 
**2)What is the impact of of bigger size on performance? Can it be explained by operators implementation overhead?**
Im większy rozmiar danych tym większy jest czas wykonywania się danej operacji, co jest przewidywalne, 
powodem dla którego się to dzieje mogą być operatory dla typów przez nas zdefiniowanych których czas wykonywania znacząco się podnosi 
w dla dużych typów danych, bo tych operacji jest do wykonania więcej.

# Summary
CPU: 2,6 GHz Czterordzeniowy procesor Intel Core i7
Run on (8 X 2600 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 6144 KiB (x1)
Load Average: 2.74, 2.91, 2.84
RAM: 16 GB 2133 Mhz LPDDR3

Wyniki benchamrków były uzależnione od sprzętu na którym je przeprowadzono, rozmiarze danych, oraz 
wielkości kontenerów. Przeprowadzone były w taki sposób aby uzyskać jak najbardziej optymalne wyniki czasowe, 
jaki i obliczeniowe. Benchamrki pokazują jak duży wpływ na szybkość programu może mieć nieopowiedni typ kontera lub danych.


