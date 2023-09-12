#include<iostream>
#include<map>
#include<vector>
#include "Graph.h"

/*  ˼·
    1�����ҵ�������������˶���
    2���Ӹ߲㵽�Ͳ������·�����ӵͲ㵽�߲�û��·��
    3��ά��һ������N��Ԫ�ص�·�����У�����Ȩ�������ҵ�TopN
*/

// �ҵ�����ʼ�㵽�յ����������
std::vector<std::vector<int>> topSort(Graph m_graph) {
    // ʹ��vector�洢���������˳��
    std::vector<std::vector<int>> top_queue;
    // ����һ�ݣ����޸�ԭʼ���ݵ�ֵ
    Graph graph(m_graph);

    // ֻҪ��������û�н��������ϵĽ�ǰ�����Ϊ0�ļ��뵽������
    while (!graph.isEnd()) {
        std::vector<int> temp_queue;
        for (int i = 0; i < graph._edges; ++i) {
            if (graph._pre_edges[i] == 0) {
                temp_queue.emplace_back(i);
                graph._pre_edges[i] = -1;
            }
        }

        for (int i = 0; i < temp_queue.size(); ++i) {
            // �������еıߵĳ��߶����м�һ�������¾���
            for (int j = 0; j < graph._edges; ++j) {
                if (graph._matrix[temp_queue[i]][j] != 0) {
                    graph._matrix[temp_queue[i]][j] = 0;
                    graph._pre_edges[j] -= 1;
                }
            }
        }

        top_queue.emplace_back(temp_queue);
    }
    return top_queue;
}

// �Ե�ǰ�����ľ����Ľ�㰴�����õ�������˳������
bool nodeSort(std::vector<std::vector<int>>top_queue, std::vector<int>& mid_node){
    int len = top_queue.size();
    int count = mid_node.size() - 2;
    std::vector<int> node_sort;
    node_sort.emplace_back(mid_node[0]);

    // ͨ���ж�top_queue�ҳ���ȷ������˳��
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < top_queue[i].size(); ++j){
            // ��ǰ�����ڶ���ѭ��������
            int flag = 0;
            for(int k = 1; k < mid_node.size()-1; ++k){
                if(top_queue[i][j] == mid_node[k]){
                    node_sort.emplace_back(mid_node[k]);
                    mid_node.erase(mid_node.begin()+k);
                    count -= 1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
    }

    node_sort.emplace_back(mid_node[mid_node.size()-1]);
    // �������������޷������������
    if(count>0)return false;
    mid_node = node_sort;
    return true;
}

// Ѱ���������֮���ȫ��·�������������
void Graph::findTwoPoint(int point1, int point2, mpath path, std::vector<mpath>& res){
    if(point1 == point2){
        path.m_queue.emplace_back(point2);

        // ����Ȩ�صĴ�С����push
        if(res.empty()){
            res.emplace_back(path);
        }
        else{
            int i = 0;
            while(path.weight < res[i].weight){
                ++i;
            }
            res.insert(res.begin() + i, path);
        }
        return;
    }
    // std::cout<<point1<<":"<<point2<<" "<<'\n';

    path.m_queue.emplace_back(point1);
    for(int i = 0; i < _edges; ++i){
        // �˳�ѭ��
        if(_matrix[point1][i] != 0){
            path.weight += _matrix[point1][i];
            findTwoPoint(i, point2, path, res);
            path.weight -= _matrix[point1][i];
        }
    }
    path.m_queue.emplace_back(point1);
}

// ͨ���õ���˳���ҳ����е�·����Ȩֵ��������
void allPath(std::vector<int> nodes, Graph m_graph, int n, int first, int second){
    // �Եõ������򹹽�hashmap����ȷ�����ʵĹ����ж����һ�α���
    mpath path;
    std::vector<mpath> res;

    // �ҳ���ʼ�㵽�յ������·����Ȼ���ų���û��ͨ����·��
    m_graph.findTwoPoint(first,second,path,res);
    
    // ���õ��Ľ���ϣ��
    std::map<int, bool> m_map;
    for(int i = 0; i < nodes.size(); ++i){
        m_map[nodes[i]] = 1;
    }
    // for(int i = 0; i < res.size(); ++i){
    //     for(int j = 0; j < res[i].m_queue.size(); ++j){
    //         std::cout<<res[i].m_queue[j]<<"->";
    //     }
    //     std::cout<<"weight:"<<res[i].weight<<'\n';
    // } 
    // �õ�topN���������븴���ˣ��Ҳ�
    std::vector<mpath> ans;
    for(int i = 0; i < res.size(); ++i){
        // ���·�����Ƿ����nodes���
        int count = 0;
        for(int j = 0; j < res[i].m_queue.size(); ++j){
            if(m_map.find(res[i].m_queue[j]) != m_map.end()){
                count++;
            }
        }
        if(count == nodes.size() && ans.size() < n){
            ans.emplace_back(res[i]);
        }
    }
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].m_queue.size()-1; ++j){
            std::cout<<ans[i].m_queue[j]<<"->";
        }
        std::cout<<ans[i].m_queue[ans[i].m_queue.size()-1]<<"  ";
        std::cout<<"weight:"<<ans[i].weight<<'\n';
    } 
}

void showVector(std::vector<int> mid_node){
    for(auto i : mid_node){
        std::cout<<i<<' ';
    }   
}

int main() {

    int matrix_[6][6] = { {0,5,5,4,0,0}, {0,0,0,1,0,0}, {0,0,0,0,7,0},
                        {0,0,0,0,2,8}, {0,0,0,0,0,1}, {0,0,0,0,0,0} };
    int** matrix = new int* [6];
    for (int i = 0; i < 6; ++i) {
        matrix[i] = matrix_[i];
    }
    Graph m_graph(matrix, 6, 6);
    // �õ���������
    std::vector<std::vector<int>>top_queue = topSort(m_graph);

    std::vector<int> mid = {0, 1, 5};
    int n = 3;

    bool b = nodeSort(top_queue, mid);

    allPath(mid, m_graph, n, mid[0], mid[mid.size() - 1]);

    std::cout<<"Sdadsadad!!!";
    system("PAUSE");
    return 0;
}