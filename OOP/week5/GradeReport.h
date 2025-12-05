#pragma once

class GradeReport {
public:
	double* grades = nullptr;
	int size = 0;
	char* reportName;

public:
	GradeReport() = default;
	GradeReport(const double* grades, int size, const char* name);
	GradeReport(const GradeReport& gr);
	~GradeReport();
	GradeReport& operator= (const GradeReport& gr);

private:
	void CopyFrom(const GradeReport& gr);
	void free();

public:
	int GetSize() const;
	char* GetName() const;
	double Average() const;

};