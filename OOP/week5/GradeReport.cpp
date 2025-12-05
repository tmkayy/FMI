#include "GradeReport.h";
#include <cstring>;

GradeReport::GradeReport() {
};

GradeReport::GradeReport(const double* grades, int size, const char* name)
{
	if (!name) {
		strcpy(this->GetName(), "");
	}
	if (!grades) {
		this->size = 0;
		this->grades = new double[this->size];
	}
	this->size = size;
	this->grades = new double[size];
	for (size_t i = 0; i < size; i++)
	{
		this->grades[i] = grades[i];
	}
	strcpy(this->GetName(), name);
}

GradeReport::GradeReport(const GradeReport& gr) {
	CopyFrom(gr);
}

GradeReport::~GradeReport()
{
	free();
}

void GradeReport::free()
{
	delete[] this->grades;
	grades = nullptr;
	delete[] this->reportName;
	reportName = nullptr;
}

int GradeReport::GetSize() const
{
	return this->size;
}

char* GradeReport::GetName() const
{
	return this->reportName;
}

double GradeReport::Average() const
{
	double sum = 0;
	for (size_t i = 0; i < this->GetSize(); i++)
	{
		sum += this->grades[i];
	}
	return sum / this->GetSize();
}

GradeReport& GradeReport::operator=(const GradeReport& gr)
{
	if (this != &gr) {
		CopyFrom(gr);
		gr.~GradeReport();
		return *this;
	}
	return *this;
}

void GradeReport::CopyFrom(const GradeReport& gr) {
	this->grades = new double[gr.size];
	this->size = gr.size;
	for (size_t i = 0; i < gr.size; i++)
	{
		grades[i] = gr.grades[i];
	}
	strcpy(this->reportName, gr.reportName);
}