[MooCast](http://www.usaco.org/index.php?page=viewproblem2&cpid=669), have to model graph somehow and then till `N` edges we have to mark an edge, `DSU` is the thing with which we will be marking edge b/w two points.

method1


	

	  for (int i = 0; i < n; i++) {
	    for (int j = 0; j < i; j++) {
	      int d = (two[j] - two[i]) * (two[j] - two[i]) +
	              (one[j] - one[i]) * (one[j] - one[i]);
	      arr.pb({i, j, d});
	    }
	  }

	  sort(all(arr),
	       [](const info &a, const info &b) -> bool { return a.d < b.d; });

	  UnionFind dsu(n);
	  int Size = n;
	  int ans = -1;
	  
	  /* We desire to have first N edges unique in themselves(not have any direct edge already) to be in our bag */
	 
	  for (const auto &i : arr) {
	    if (!dsu.isSameSet(i.i, i.j)) { /* To avoid repeatition of edges */
	      dsu.unionSet(i.i, i.j);
	      
        /* We only want first N edges, not more than that, since no self edge hence no repeatition, therefore can apply something like this without fear */
	
	      --Size; 
	      if (Size == 1) {
	        ans = i.d;
	        break;
	      }
	    }
	  }



method2

	Binary search on the ans. (in this case the weight) 

