#include <iostream> 
#include <vector>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int n = 0;
    cout << "레코드 개수 입력" << '\n';
    cin >> n;
    vector<int> v(n);
    cout << "레코드 입력: ";
    for (int i = 0; i < n; i++) { // v[i]에 입력 레코드 저장
        cin >> v[i];
    }

    // 최대, 최소값 찾기
    int large = v[0], small = v[0];
    int i = 1;
    for (; i + 1 < n; i += 2) {
        if (v[i] < v[i + 1]) {
            if (v[i] < small) {
                small = v[i];
            }
            if (v[i + 1] > large) {
                large = v[i + 1];
            }
        }
        else {
            if (v[i + 1] < small) {
                small = v[i + 1];
            }
            if (v[i] > large) {
                large = v[i];
            }
        }
    } if (i == n - 1) { // 경계값 처리
        if (v[i] < small) {
            small = v[i];
        } else if (v[i] > large) {
            large = v[i];
        }
    }

    int width = large - small + 1; // count의 크기
    vector<int> count(width); // 크기를 지정해줘야 이후 접근이 가능함
    for (int i = 0; i < n; i++) {
        count[v[i] - small] += 1;
    }
    vector<int> acc_count;
    acc_count.push_back(count[0]);
    for (int i = 1; i < width; i++) {
        acc_count.push_back(acc_count[i - 1] + count[i]);
    }

    vector<int> answer(n);
    for (int i = n - 1; i >= 0; i--) {
        answer[acc_count[v[i] - small] - 1] = v[i];
        acc_count[v[i] - small] -= 1;
    }

    cout << "정렬된 배열: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    } cout << '\n';

    return 0;
}