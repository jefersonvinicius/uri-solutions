#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> lesser_lexicographic_list(vector<string> list1, vector<string> list2) {
    for (int i = 0; i < list1.size(); i++) {
        if (list1[i] < list2[i]) return list1;
        else if (list2[i] < list1[i]) return list2;
    }
    return list1;
}

int index_of(vector<string> items, string target) {
    vector<string>::iterator it = find(items.begin(), items.end(), target);
    if (it != items.end()) return it - items.begin();
    return -1;
}

vector<string> sorting(vector<string> names, int max_swaps, string target) {
    vector<string> result = names;
    if (result.size() == 1) return result;

    int swaps = 0;
    int index = index_of(names, target);
    while (swaps < max_swaps && index < names.size() - 1) {
        while (result[index] > result[index + 1]) {
            string tmp = result[index];
            result[index] = result[index + 1];
            result[index + 1] = tmp;
            swaps++;
            index--;
            if (swaps == max_swaps || index < 0) break;
        }
        if (index < 0) break;
        index++;
    }

    return result;
}

void print_vector(vector<string> v) {
    for (auto item : v) {
        printf("%s ", item.c_str());
    }
}

int main() {

    int n, k, instance = 1;
    while (1) {
        scanf("%d%d\n", &n, &k);
        if (n == 0 && k == 0) break;

        vector<string> names;
        char name_c[21];
        for (int i = 0; i < n; i++) {
            scanf("%s \n", name_c);
            names.push_back(name_c);
        }

        vector<vector<string>> lists;
        vector<string> answer = names;
        vector<string> sorted_names = names;
        sort(sorted_names.begin(), sorted_names.end());
        // printf("Sorted: ");
        // print_vector(sorted_names);
        // printf("\n");

        for (int i = 0; i < sorted_names.size(); i++) {
            vector<string> sorted = sorting(names, k, sorted_names[i]);
            lists.push_back(sorted);
            answer = lesser_lexicographic_list(answer, sorted);
        }

        printf("Instancia %d\n", instance);
        for (int i = 0; i < answer.size(); i++) {
            printf("%s ", answer[i].c_str());
        }
        printf("\n\n");

        instance++;
    }


    return 0;
}