
#include <vector>
#include <iostream>

std::vector<int> merge(std::vector<int>, std::vector<int>);

std::string toString(std::vector<int>);

int main() {
	std::vector<int> nums1 = {1, 3, 5, 7, 9};
	std::vector<int> nums2 = {2, 4, 6, 8, 10};

	std::cout << toString(merge(nums1, nums2)) << std::endl;
}


std::string toString(std::vector<int> nums) {
	std::string str;

	for(auto i = nums.begin(); i != --nums.end(); ++i) {
		str += std::to_string(*i);
		str += ',';
	}

	str += std::to_string(nums.back());

	return str;
}

std::vector<int> merge(std::vector<int> nums1, std::vector<int> nums2) {

	auto iter1 = nums1.begin();
	auto iter2 = nums2.begin();

	std::vector<int> nums(nums1.size() + nums2.size());
	auto iter = nums.begin();

	while(iter1 != nums1.end() && iter2 != nums2.end()) {
		if(*iter1 < *iter2) {
			*iter = *iter1;
			iter1++;
		}else {
			*iter = *iter2;
			iter2++;
		}
		iter++;
	}

	while(iter1 != nums1.end()) {
		*iter = *iter1;
		iter1++;
	}

	while(iter2 != nums2.end()) {
		*iter = *iter2;
		iter2++;
	}

	return nums;
}

int median(std::vector<int> nums) {
	
	if(nums.size() % 2 == 0) {
		//oi what is this
		//this aint to stat app you fuck
		return (nums[nums.size() / 2] + nums[(nums.size() / 2) + 1]) / 2.0;
	}else {
		return nums[nums.size() / 2];
	}

}

