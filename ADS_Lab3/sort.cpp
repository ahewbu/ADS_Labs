#include <iostream>
#include <vector>

using namespace std;

struct Stats {
    size_t copy_count = 0;
    size_t compare_count = 0;
    double time = 0;
};


Stats selectionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    Stats stat;
    clock_t start, finish;

    start = clock();
    for (auto it = begin; it != end - 1; it++)
    {

        auto min_it = it;


        for (auto jt = it + 1; jt != end; jt++)
        {
            stat.compare_count++;
            if (*jt < *min_it)
            {
                min_it = jt;
            }
        }
        /*int tmp = *min_it;
        *min_it = *it;
        *it = tmp;*/
        stat.copy_count += 3;
        std::swap(*min_it, *it);
    }
    finish = clock();
    stat.time = (double(finish - start)) / (double(CLOCKS_PER_SEC));

    return stat;
}

Stats shaker_sort(vector<int>::iterator begin, vector<int>::iterator end)
{
    Stats stat;
    clock_t start, finish;
    auto left = begin;
    auto right = end - 1;
    start = clock();
    while (left < right)
    {

        for (auto i = left; i < right; ++i)
        {
            stat.compare_count += 1;
            if (*i > *(i + 1))
            {
                swap(*i, *(i + 1));
                stat.copy_count += 3;
            }
        }
        --right;

        for (auto j = right; j > left; --j)
        {
            stat.compare_count += 1;
            if (*j < *(j - 1))
            {
                swap(*j, *(j - 1));
                stat.copy_count += 3;
            }
        }
        ++left;
    }
    finish = clock();
    stat.time = (double(finish - start)) / (double(CLOCKS_PER_SEC));
    return stat;
}


Stats comb(vector<int>::iterator begin, vector<int>::iterator end)
{
    Stats stat;
    clock_t start, finish;
    double factor = 1.24773309;
    int step = int(end - begin);
    start = clock();
    while (step >= 1)
    {
        for (auto i = begin; i + step < end; ++i)
        {
            if (*i > *(i + step))
            {
                swap(*i, *(i + step));
                stat.copy_count += 3;
            }
            stat.compare_count += 1;
        }
        step /= factor;
    }
    finish = clock();
    stat.time = (double(finish - start)) / (double(CLOCKS_PER_SEC));
    return stat;
}




std::vector<int> generateRandomArray(size_t size) {
    std::vector<int> res;

    for (size_t i = 0; i < size; i++)
    {
        res.push_back(rand() % 100);
    }
    return res;
}


std::vector<int> generateSortArray(size_t size) {
    std::vector<int> res;

    for (size_t i = 0; i < size; i++)
    {
        res.push_back(i);
    }
    return res;
}


std::vector<int> generateReverseSortArray(size_t size) {
    std::vector<int> res;

    for (size_t i = size; i > 0; --i)
    {
        res.push_back(i);
    }
    return res;
}

int main() {

    srand(time(NULL));
    std::vector<int> v1, v2, v3;

    Stats stat1, stat2, stat3;

    v1 = generateSortArray(1000);
    v2 = generateReverseSortArray(1000);


    stat1 = comb(v1.begin(), v1.end());
    stat2 = comb(v2.begin(), v2.end());

    double avcompare = 0, avcopy = 0;
    for (size_t i = 0; i < 100; ++i) {
        v3 = generateRandomArray(1000);
        stat3 = comb(v3.begin(), v3.end());
        avcompare += stat3.compare_count;
        avcopy += stat3.copy_count;
        v3.clear();
    }
    avcompare /= 100;
    avcopy /= 100;
    stat3.compare_count = avcompare;
    stat3.copy_count = avcopy;

    cout << "Number of copies for sorted array: " << stat1.copy_count << endl;
    cout << "Number of compares for sorted array: " << stat1.compare_count << endl;
    cout << "Number of copies for reverse-sorted array: " << stat2.copy_count << endl;
    cout << "Number of compares for reverse-sorted array: " << stat2.compare_count << endl;
    cout << "Number of copies for random array: " << stat3.copy_count << endl;
    cout << "Number of compares for random array: " << stat3.compare_count << endl;



    return 0;

}