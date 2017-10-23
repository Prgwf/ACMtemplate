// std::mt19937 rng_engine{randutils::auto_seed_128{}.base()};
std::mt19937 rng_engine{(size_t)(new char)};
std::uniform_int_distribution<int> dist{1, 1000};//1-1000 inclusive
int rand_integer = dist(rng_engine);
