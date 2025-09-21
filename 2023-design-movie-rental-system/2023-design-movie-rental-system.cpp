struct MovieNode{
    int shop, movie, price;
    bool operator < (const MovieNode & other) const {
        if(price != other.price) return price < other.price;
        if(shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    }
};
class MovieRentingSystem {
    unordered_map<string, MovieNode> movieMap;
    unordered_map<int, set<MovieNode>> availableMovies;
    set<MovieNode> rentedSet;
    string makeKey(int shop, int movie){
        return to_string(shop) + ":" + to_string(movie);
    }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &ent: entries){
            int shop = ent[0], movie = ent[1], price = ent[2];
            MovieNode node{shop, movie, price};
            movieMap[makeKey(shop, movie)] = node;
            availableMovies[movie].insert(node);
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if(availableMovies.count(movie) == 0) return res;
        auto &s = availableMovies[movie];
        int count = 0;
        for (auto it = s.begin(); it != s.end() && count < 5; ++it, ++count) {
            res.push_back(it->shop);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        string k = makeKey(shop, movie);
        MovieNode node = movieMap[k];
        availableMovies[movie].erase(node);
        rentedSet.insert(node);
    }
    
    void drop(int shop, int movie) {
        string k = makeKey(shop, movie);
        MovieNode node = movieMap[k];
        rentedSet.erase(node);
        availableMovies[movie].insert(node);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count = 0;
        for (auto it = rentedSet.begin(); it != rentedSet.end() && count < 5; ++it, ++count) {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};