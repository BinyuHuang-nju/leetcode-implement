#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

class Solution_false { // the elements with the same key(count) in the array
        // should be sorted by the sequense of letters,
        // while the quicksort in not stable.
private:
    struct Word {
        string word;
        int count;
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hashtable;
        for (string word : words)
            hashtable[word]++;
        vector<Word> word_array;
        Word word_temp;
        for (map<string, int>::iterator iter = hashtable.begin(); iter != hashtable.end(); iter++) {
            word_temp.word = iter->first;
            word_temp.count = iter->second;
            word_array.push_back(word_temp);
        }
        select_elinear(word_array, 0, word_array.size() - 1, k);
        vector<string> results;
        for (int i = 0; i < k; i++)
            results.push_back(word_array[i].word);
        return results;
    }
private:

    void select_elinear(vector<Word>& word_array, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(word_array, p, r);
        int x = q - p + 1;
        if (x == k)
            return;
        else if (x < k)
            select_elinear(word_array, q + 1, r, k - x);
        else
            select_elinear(word_array, p, q - 1, k);
    }
    int partition(vector<Word>& word_array, int p, int r) {
        int pivot = word_array[r].count;
        int i = p;
        for (int j = p; j < r ; j++) {
            if (word_array[j].count > pivot) {
                swap(word_array[i], word_array[j]);
                i++;
            }
        }
        swap(word_array[i], word_array[r]);
        return i;
    }
    void swap(Word& x, Word& y) {
        Word temp = x;
        x = y;
        y = temp;
    }
};

class Solution_false2 {
    // solve the problem 1 but the sequense in the top K elements may not be sorted
       // by the key(count).
private:
    struct Word {
        string word;
        int count;
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hashtable;
        for (string word : words)
            hashtable[word]++;
        vector<Word> word_array;
        Word word_temp;
        for (map<string, int>::iterator iter = hashtable.begin(); iter != hashtable.end(); iter++) {
            word_temp.word = iter->first;
            word_temp.count = iter->second;
            word_array.push_back(word_temp);
        }
        select_elinear(word_array, 0, word_array.size() - 1, k); // from bigger to smaller
        int searched = 0, pre_searched = 0;
        while (searched <= word_array.size()) {
            if (searched == word_array.size() || word_array[searched].count != word_array[pre_searched].count) {
                quicksort(word_array, pre_searched, searched - 1); // from smaller to bigger
                if (searched > k)
                    break;
                pre_searched = searched;
            }
            searched++;
        }
        vector<string> results;
        for (int i = 0; i < k; i++)
            results.push_back(word_array[i].word);
        return results;
    }
private:
 
    void select_elinear(vector<Word>& word_array, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(word_array, p, r);
        int x = q - p + 1;
        if (x == k)
            return;
        else if (x < k)
            select_elinear(word_array, q + 1, r, k - x);
        else
            select_elinear(word_array, p, q - 1, k);
    }
    int partition(vector<Word>& word_array, int p, int r) {
        int pivot = word_array[r].count;
        int i = p;
        for (int j = p; j < r; j++) {
            if (word_array[j].count > pivot) {
                swap(word_array[i], word_array[j]);
                i++;
            }
        }
        swap(word_array[i], word_array[r]);
        return i;
    }
    void swap(Word& x, Word& y) {
        Word temp = x;
        x = y;
        y = temp;
    }
private:
    void quicksort(vector<Word>& word_array, int p, int r) {
        if (p < r) {
            int q = partition_reverse(word_array, p, r);
            quicksort(word_array, p, q - 1);
            quicksort(word_array, q + 1, r);
        }
    }
    int partition_reverse(vector<Word>& word_array, int p, int r) {
        string pivot = word_array[r].word;
        int i = p;
        for (int j = p; j < r; j++) {
            if (word_array[j].word < pivot) {
                swap(word_array[i], word_array[j]);
                i++;
            }
        }
        swap(word_array[i], word_array[r]);
        return i;
    }
};

class Solution {
private:
    struct Word {
        string word;
        int count;
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hashtable;
        for (string word : words)
            hashtable[word]++;
        vector<Word> word_array;
        Word word_temp;
        for (map<string, int>::iterator iter = hashtable.begin(); iter != hashtable.end(); iter++) {
            word_temp.word = iter->first;
            word_temp.count = iter->second;
            word_array.push_back(word_temp);
        }
        quicksort(word_array, 0, word_array.size() - 1); // from bigger to smaller
        int searched = 0, pre_searched = 0;
        while (searched <= word_array.size()) {
            if (searched == word_array.size() || word_array[searched].count != word_array[pre_searched].count) {
                quicksort_reverse(word_array, pre_searched, searched - 1); // from smaller to bigger
                if (searched > k)
                    break;
                pre_searched = searched;
            }
            searched++;
        }
        vector<string> results;
        for (int i = 0; i < k; i++)
            results.push_back(word_array[i].word);
        return results;
    }
private:

 /*   void select_elinear(vector<Word>& word_array, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(word_array, p, r);
        int x = q - p + 1;
        if (x == k)
            return;
        else if (x < k)
            select_elinear(word_array, q + 1, r, k - x);
        else
            select_elinear(word_array, p, q - 1, k);
    }*/
    void quicksort(vector<Word>& word_array, int p, int r) {
        if (p < r) {
            int q = partition(word_array, p, r);
            quicksort(word_array, p, q - 1);
            quicksort(word_array, q + 1, r);
        }
    }
    int partition(vector<Word>& word_array, int p, int r) {
        int pivot = word_array[r].count;
        int i = p;
        for (int j = p; j < r; j++) {
            if (word_array[j].count > pivot) {
                swap(word_array[i], word_array[j]);
                i++;
            }
        }
        swap(word_array[i], word_array[r]);
        return i;
    }
    void swap(Word& x, Word& y) {
        Word temp = x;
        x = y;
        y = temp;
    }
private:
    void quicksort_reverse(vector<Word>& word_array, int p, int r) {
        if (p < r) {
            int q = partition_reverse(word_array, p, r);
            quicksort_reverse(word_array, p, q - 1);
            quicksort_reverse(word_array, q + 1, r);
        }
    }
    int partition_reverse(vector<Word>& word_array, int p, int r) {
        string pivot = word_array[r].word;
        int i = p;
        for (int j = p; j < r; j++) {
            if (word_array[j].word < pivot) {
                swap(word_array[i], word_array[j]);
                i++;
            }
        }
        swap(word_array[i], word_array[r]);
        return i;
    }
};


int main() {
    Solution sol;
    vector<string> words = { "glarko","zlfiwwb","nsfspyox","pwqvwmlgri","qggx","qrkgmliewc","zskaqzwo","zskaqzwo","ijy","htpvnmozay","jqrlad","ccjel","qrkgmliewc","qkjzgws","fqizrrnmif","jqrlad","nbuorw","qrkgmliewc","htpvnmozay","nftk","glarko","hdemkfr","axyak","hdemkfr","nsfspyox","nsfspyox","qrkgmliewc","nftk","nftk","ccjel","qrkgmliewc","ocgjsu","ijy","glarko","nbuorw","nsfspyox","qkjzgws","qkjzgws","fqizrrnmif","pwqvwmlgri","nftk","qrkgmliewc","jqrlad","nftk","zskaqzwo","glarko","nsfspyox","zlfiwwb","hwlvqgkdbo","htpvnmozay","nsfspyox","zskaqzwo","htpvnmozay","zskaqzwo","nbuorw","qkjzgws","zlfiwwb","pwqvwmlgri","zskaqzwo","qengse","glarko","qkjzgws","pwqvwmlgri","fqizrrnmif","nbuorw","nftk","ijy","hdemkfr","nftk","qkjzgws","jqrlad","nftk","ccjel","qggx","ijy","qengse","nftk","htpvnmozay","qengse","eonrg","qengse","fqizrrnmif","hwlvqgkdbo","qengse","qengse","qggx","qkjzgws","qggx","pwqvwmlgri","htpvnmozay","qrkgmliewc","qengse","fqizrrnmif","qkjzgws","qengse","nftk","htpvnmozay","qggx","zlfiwwb","bwp","ocgjsu","qrkgmliewc","ccjel","hdemkfr","nsfspyox","hdemkfr","qggx","zlfiwwb","nsfspyox","ijy","qkjzgws","fqizrrnmif","qkjzgws","qrkgmliewc","glarko","hdemkfr","pwqvwmlgri" };
    vector<string> results = sol.topKFrequent(words, 14);
    return 0;
}