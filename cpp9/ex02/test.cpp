/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artclave <artclave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:24:41 by artclave          #+#    #+#             */
/*   Updated: 2024/07/21 17:39:45 by artclave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

#define FRONT 0
#define BACK 1

// Primary class template PmergeMe
template <typename T>
class PmergeMe {
private:
    T container; // Container of type T (std::vector<int> or std::list<int>)

    // Private utility functions
    T divide(int section) {
        int odd = container.size() % 2;
        T subcontainer;
        auto it = container.begin();
        for (int i = 0; i < section * (static_cast<int>(container.size() / 2) + odd); i++)
            it++;
        for (int i = 0; i < static_cast<int>(container.size()) / 2 + (section * odd); i++) {
            subcontainer.push_back(*it);
            it++;
        }
        return subcontainer;
    }

    void sort();
    void merging(const PmergeMe& other);
public:
    // Constructors
    PmergeMe() {
        std::cout << "Default constructor called for PmergeMe\n";
    }

    PmergeMe(const T& cont) : container(cont) {
        std::cout << "Constructor called for PmergeMe with container\n";
    }

    // Member function algo
    T algo() {
        if (container.size() < 3) {
            sort();
            return container;
        }
        PmergeMe sub_a(divide(FRONT));
        sub_a.sort();
        PmergeMe sub_b(divide(BACK));
        sub_b.sort();
        sub_b.merging(sub_a);
        container = sub_b.container;
        return container;
    }

    // Function to print container elements
    void print_container(std::string str = "Container: ") {
        std::cout << str;
        for (auto it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
};

// Specialization for std::vector<int>
template <>
std::vector<int> PmergeMe<std::vector<int>>::divide(int section) {
    int odd = container.size() % 2;
    std::vector<int> subvector;
    auto it = container.begin();
    for (int i = 0; i < section * (static_cast<int>(container.size() / 2) + odd); i++)
        it++;
    for (int i = 0; i < static_cast<int>(container.size()) / 2 + (section * odd); i++) {
        subvector.push_back(*it);
        it++;
    }
    return subvector;
}

// Specialization for std::vector<int> sorting
template <>
void PmergeMe<std::vector<int>>::sort() {
    std::sort(container.begin(), container.end());
}

// Specialization for std::vector<int> merging
template <>
void PmergeMe<std::vector<int>>::merging(const PmergeMe<std::vector<int>>& other) {
    std::vector<int> result;
    std::merge(container.begin(), container.end(), other.container.begin(), other.container.end(), std::back_inserter(result));
    container = result;
}

template <>
void PmergeMe<std::list<int>>::sort() {
    container.sort();
}
template <>
void PmergeMe<std::list<int>>::merging(const PmergeMe<std::list<int>>& other) {
	std::list<int> temp = other.container;  // Make a copy to avoid const issues
    container.merge(temp);
}
// Specialization for std::list<int> sorting (already provided in the class template)
// Specialization for std::list<int> merging (already provided in the class template)

int main() {
    // Example usage with std::vector<int>
    std::vector<int> vec = {5, 3, 1, 4, 2};
    PmergeMe<std::vector<int>> vecObj(vec);
    vecObj.algo();
    vecObj.print_container("Vector: "); // Output: Vector: 1 2 3 4 5

    // Example usage with std::list<int>
    std::list<int> lst = {50, 30, 10, 40, 20};
    PmergeMe<std::list<int>> listObj(lst);
    listObj.algo();
    listObj.print_container("List: "); // Output: List: 10 20 30 40 50

    return 0;
}
