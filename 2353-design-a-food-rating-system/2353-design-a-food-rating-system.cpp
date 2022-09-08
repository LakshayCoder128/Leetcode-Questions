class FoodRatings
{
    public:
        map<string, pair<string, int>> m;	//food => cuisine => rating
        map<string,set<pair<int,string>>>n; // cuisine =>rating => food
        FoodRatings(vector<string> &foods, vector<string> &cuisines, vector< int > &ratings)
        {
            for (int i = 0; i < foods.size(); i++)
            {
                m[foods[i]] = { cuisines[i],
                    ratings[i]
                };
                n[cuisines[i]].insert({-ratings[i],foods[i]}) ;
            }
        }

    void changeRating(string food, int newRating)
    {
        if (m.find(food) != m.end())
        {   
            int preRating = m[food].second;
            m[food].second = newRating;
            n[m[food].first].erase({-preRating,food});
             n[m[food].first].insert({-newRating,food});
        }
    }

    string highestRated(string cuisine) {
        
            return n[cuisine].begin()->second;
        
        
    }
};

/**
 *Your FoodRatings object will be instantiated and called as such:
 *FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 *obj->changeRating(food,newRating);
 *string param_2 = obj->highestRated(cuisine);
 */