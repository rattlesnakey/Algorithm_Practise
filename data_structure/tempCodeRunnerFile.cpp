// 从大到小排列
    sort(e.begin(),e.end(),cmp);

    // 初始化father矩阵
    vector<int >father(n);
    for(int i=0;i<n;i++){
        father[i] = i;
    }

    int sum = 0;
    int count = 0;
    // 遍历所有的边，选n-1条边进来
    for(int i=0;i<e.size();i++){
        edge cur_edge = e[i];
        int cur_left = cur_edge.left;
        int cur_right = cur_edge.right;
        int left_father = find_father(father,cur_left);
        int right_father = find_father(father,cur_right);
        if(left_father != right_father){
            father[left_father] = right_father;
            sum += cur_edge.weight;
            count ++;
        }
        // 找到n-1条边就出去
        if (count == n-1){
            break;
        }
    }
    cout<<sum<<endl;