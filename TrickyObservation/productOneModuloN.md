Motivation: https://codeforces.com/contest/1514/problem/C
# key observation
 - we will have to take no.s that are coprime
   - WHY? consider one no. 6 and `n` be 8
   - Their product will be multiple of 6
   - Modulous of product by 8 will be however `multiple` of `2`
   - Therefore coprime no.s should be taken into account. 
 - **What if** even after that `product % n` still not equal to 1
 - exclude the no. `product % n` from your list of no. 
   - `product % n` will be in `1` to `n - 1` no need to worry. 
   - just exclude that from array 
   - and you will get your answer. 
