//#include <iostream>
//#include <fstream>
//
//namespace consts {
//	const int MAX_SIZE = 10;
//	const int MAX_VECTORS = 50;
//}
//
//namespace zad1 {
//	void SumAndProduct(const char* fname1, const char* fname2) {
//		if (!fname1 || !fname2)
//			return;
//
//		std::ifstream ifs(fname1);
//		int num1 = 0, num2 = 0;
//		if (!ifs.is_open()) {
//			ifs.close();
//			return;
//		}
//
//		ifs >> num1; ifs.ignore(); ifs >> num2;
//		ifs.close();
//
//		std::ofstream ofs(fname2);
//		if (!ofs.is_open())
//		{
//			ofs.close();
//			return;
//		}
//
//		ofs << num1 + num2 << std::endl;
//		ofs << num1 * num2; ofs.close();
//	}
//}
//
//namespace zad2 {
//	void saveEven(std::ifstream& ifseven, int* evenarr, int& size) {
//		if (!ifseven.is_open())
//		{
//			ifseven.close();
//			return;
//		}
//		for (size_t i = 0; i < consts::MAX_SIZE; i++)
//		{
//			if (ifseven.eof())
//				break;
//			ifseven >> evenarr[i]; ifseven.ignore(); size++;
//			if (ifseven.eof())
//				break;
//			int ignored = 0;
//			ifseven >> ignored; ifseven.ignore();
//		}
//		ifseven.close();
//	}
//
//	void saveOdd(std::ifstream& ifsodd, int* oddarr, int& size) {
//		if (!ifsodd.is_open())
//		{
//			ifsodd.close();
//			return;
//		}
//		for (size_t i = 0; i < consts::MAX_SIZE; i++)
//		{
//			if (ifsodd.eof())
//				break;
//			int ignored = 0;
//			ifsodd >> ignored; ifsodd.ignore();
//			if (ifsodd.eof())
//				break;
//			ifsodd >> oddarr[i]; ifsodd.ignore(); size++;
//		}
//		ifsodd.close();
//	}
//
//
//	void saveEvenAndOdd(const char* fname) {
//		if (!fname)
//			return;
//
//		std::ifstream ifseven(fname);
//
//		if (!ifseven.is_open())
//		{
//			ifseven.close();
//			return;
//		}
//		int evenarr[consts::MAX_SIZE]{};
//		int oddarr[consts::MAX_SIZE]{};
//		int sizeven = 0;
//		int sizeodd = 0;
//		saveEven(ifseven, evenarr, sizeven);
//
//		std::ifstream ifsodd(fname);
//
//		if (!ifsodd.is_open())
//		{
//			ifsodd.close();
//			return;
//		}
//
//		saveOdd(ifsodd, oddarr, sizeodd);
//
//		std::ofstream ofseven("even.txt");
//
//		if (!ofseven.is_open())
//		{
//			ofseven.close();
//			return;
//		}
//
//		for (size_t i = 0; i < sizeven; i++)
//		{
//			ofseven << evenarr[i] << std::endl;
//		}
//		ofseven.close();
//
//		std::ofstream ofsodd("odd.txt");
//
//		if (!ofsodd.is_open())
//		{
//			ofsodd.close();
//			return;
//		}
//
//		for (size_t i = 0; i < sizeodd; i++)
//		{
//			ofsodd << oddarr[i] << std::endl;
//		}
//		ofsodd.close();
//	}
//}
//
//namespace zad3 {
//	struct Vector {
//		int x = 0;
//		int y = 0;
//		int z = 0;
//	};
//
//	struct VectorSpace {
//		Vector vectors[consts::MAX_VECTORS];
//		int vCount = 0;
//	};
//
//	Vector makeVector(int x, int y, int z) {
//		Vector v;
//		v.x = x; v.y = y; v.z = z;
//		return v;
//	}
//
//	void addToVectorSpace(VectorSpace& vs, const Vector& v) {
//		if (vs.vCount == consts::MAX_VECTORS)
//			return;
//		vs.vectors[vs.vCount] = makeVector(v.x, v.y, v.z);
//		vs.vCount++;
//	}
//
//	void serializeVector(const Vector& v, std::ofstream ofs) {
//		if (!ofs.is_open()) {
//			ofs.close();
//			return;
//		}
//		ofs << '<' << v.x << ", " << v.y << ", " << v.z << '>' << std::endl;
//	}
//
//	Vector deserializeVector(std::ifstream ifs) {
//		if (!ifs.is_open()) {
//			ifs.close();
//			return;
//		}
//		Vector v;
//		ifs.ignore();
//		ifs >> v.x; ifs.ignore(); ifs.ignore();
//		ifs >> v.y; ifs.ignore(); ifs.ignore();
//		ifs >> v.z; ifs.ignore(); ifs.ignore();
//	}
//}
//
//int main() {
//	/*zad1::SumAndProduct("nums1.txt", "nums2.txt");*/
//	/*zad2::saveEvenAndOdd("nums.txt");*/
//	return 0;
//}