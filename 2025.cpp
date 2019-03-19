#include <iostream>
#include <cmath>

int t_2025() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int num_teams, num_fighters;
        std::cin >> num_fighters >> num_teams;
        int fighters_per_team = num_fighters / num_teams;
        int extra_fighters = num_fighters % num_teams;
        int result = ((num_fighters * (num_fighters - 1)) / 2)
                - ((num_teams - extra_fighters) * ((fighters_per_team * (fighters_per_team - 1)) / 2))
                - (extra_fighters * (((fighters_per_team + 1) * fighters_per_team) / 2));
        std::cout << result << std::endl;
    }
    return 0;
}