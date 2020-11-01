/*
Ernest Kim
10/25/20
1 hour
Memory usage: 71.5mb
*/

/*
Given the array candies and the integer extraCandies, where candies[i] represents 
the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies among the kids such 
that he or she can have the greatest number of candies among them. Notice that multiple 
kids can have the greatest number of candies.
*/

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    //Find greatest number
    int greatest = 0;
    
    for (int x : candies) {
        if (x > greatest) {
            greatest = x;
            cout << "Greatest is now: " << greatest << "\n";
        }
    }
    
    vector<bool> result;
    
    //Go through kids candies
    for (int x : candies) {
        if ((x + extraCandies) >= greatest) {
            cout << "Max is " << (x + extraCandies) << " pushing true\n";
            result.push_back(true);
        } else {
            cout << "Max is " << (x + extraCandies) << " pushing false\n";
            result.push_back(false);
        }
    }
    
    return result;
}