int n,k,w;
	cin>>n>>k>>w;
	vector< array<int,3> >arr;
	int st,dur;
	for(int i=0;i<n;i++){
		cin>>st>>dur;
		arr.push_back({st,dur,i});
	}
    sort(begin(arr),end(arr));
    priority_queue< array<int,3>,vector<array<int,3> >,greater<array<int,3> > >pq;
    int cur_time=0;
	int pos=0,idx;
	vector<int>ans(n,0);
	while(pos<n || pq.size()>0){
        if(pq.size()==0){
			cur_time=max(cur_time,arr[pos][0]);
		}
		while(pos<n && cur_time>=arr[pos][0]){
			pq.push({arr[pos][1],arr[pos][0],pos});
			pos++;
		}
         dur=pq.top()[0];
		 st=pq.top()[1];
		 idx=pq.top()[2];
		 pq.pop();
		 int tt=dur*k;
		 int wait_time=cur_time-st;
		 int wait_cost=wait_time*w;
		 if(tt>=wait_cost)
		   ans[idx]=tt-wait_cost;
		  cur_time+=dur; 
	}
   for(int i=0;i<n;i++){
	cout<<ans[i]<<' '; 
   }
   cout<<endl;
