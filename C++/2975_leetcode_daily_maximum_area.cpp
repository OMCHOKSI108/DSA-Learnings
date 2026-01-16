void findLen(vector<int>& fences, int sz, bool calM){
    sort(fences.begin(), fences.end());
    for (int l=0; l<sz-1; l++){
        int L=fences[l];
        for (int r=l+1; r<sz; r++){
            int Len=fences[r]-L;// compute the Len
            // 1 function with 2 options
            if (calM){// compute maxL
                // to judge whether Len>maxL and Len is in seen
                if(Len>maxL && binary_search(seen.begin(), seen.end(),Len)) 
                    maxL=Len;
            }
            else// otherwise add Len in seen
                seen.push_back(Len);
        }
    }
}
