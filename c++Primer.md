# emplace_back: 
	add a new element to container by constructing it, but push_back copies or moves an existing object. 

# two dimensional vector initialize
    vector<vector<int> > newOne(r, vector<int>(c, 0));

    vector<vector<int> > res;
    res.resize(r);//r行
    for (int k = 0; k < r; ++k){
        res[k].resize(c);//每行为c列
    }

Plus:recommend using {} to initialize

# operator ++ , += 1, + 1
    set: only definition of ++ and --, but not + 1.

# while else in python but no in c++
    while (j <= border[0]) {
        cout<<i<<j<<endl;
        result.push_back(matrix.at(i).at(j));
        j++; flag[0] = 1;
    }
    if (flag[0]) {j--; i++; border[3]++; flag[0] = 0;}

# length() and size()
    both are the same. length is for the consistency of c language and size is designed for STL.