#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
/*
    ��̬�滮״̬����
    ���� dp[i][j] ��ʾ����� i �е� j ��ʱ�ܻ�õ����P��ֵ������ÿ���������һ�У�ÿ��λ�õ����ֵ����������һ�е�ĳЩλ�á�
    ת�Ʒ���
        ����ÿ��λ�� j����ǰһ�п��ܵ��з�ΧΪ [j-T, j+T]��ֱ�ӱ�����Щ�е�ʱ�临�Ӷ�Ϊ O(T*M*N)���޷���������롣
    ʹ�õ��������Ż������������ֵ��
        ����ɨ�裺ά��һ������ [j-T, j]������ÿ��λ���������ֵ max_left[j]��
        �ҵ���ɨ�裺ά������ [j, j+T]�������Ҳ����ֵ max_right[j]��
        �ϲ� max_left �� max_right �õ�ÿ��λ�õ�ǰ�����ֵ��
    ���岽��
        ��ʼ����һ�е� dp ֵΪ��Ӧ���ӵ�P�㡣
        �Ժ���ÿһ�У��ֱ���� max_left �� max_right ���飬�ϲ�����µ�ǰ�е� dp ֵ��
        ���ս��Ϊ���һ�� dp �����ֵ��
*/
int main() {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<vector<int>> val_grid(N, vector<int>(M, 0));
    for (int k = 0; k < K; ++k) {
        int x, y, v;
        cin >> x >> y >> v;
        x--; // ת��Ϊ0-based����
        y--;
        val_grid[x][y] = v;
    }

    vector<int> prev_dp(M);
    for (int j = 0; j < M; ++j) {
        prev_dp[j] = val_grid[0][j];
    }

    for (int i = 1; i < N; ++i) {
        vector<int> current_dp(M, 0);
        vector<int> max_left(M, 0);
        deque<int> dq_left;

        // ����max_left����
        for (int j = 0; j < M; ++j) {
            int left = max(0, j - T);
            while (!dq_left.empty() && dq_left.front() < left) {
                dq_left.pop_front();
            }
            while (!dq_left.empty() && prev_dp[dq_left.back()] <= prev_dp[j]) {
                dq_left.pop_back();
            }
            dq_left.push_back(j);
            max_left[j] = prev_dp[dq_left.front()];
        }

        // ����max_right����
        vector<int> max_right(M, 0);
        deque<int> dq_right;
        for (int j = M - 1; j >= 0; --j) {
            int right = min(M - 1, j + T);
            while (!dq_right.empty() && dq_right.front() > right) {
                dq_right.pop_front();
            }
            while (!dq_right.empty() && prev_dp[dq_right.back()] <= prev_dp[j]) {
                dq_right.pop_back();
            }
            dq_right.push_back(j);
            max_right[j] = prev_dp[dq_right.front()];
        }

        // ����current_dp
        for (int j = 0; j < M; ++j) {
            int max_prev = max(max_left[j], max_right[j]);
            current_dp[j] = max_prev + val_grid[i][j];
        }

        prev_dp.swap(current_dp);
    }

    cout << *max_element(prev_dp.begin(), prev_dp.end()) << endl;

    return 0;
}