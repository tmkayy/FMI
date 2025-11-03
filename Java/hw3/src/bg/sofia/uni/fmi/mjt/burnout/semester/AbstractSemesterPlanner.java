package bg.sofia.uni.fmi.mjt.burnout.semester;

import bg.sofia.uni.fmi.mjt.burnout.exception.DisappointmentException;
import bg.sofia.uni.fmi.mjt.burnout.exception.InvalidSubjectRequirementsException;
import bg.sofia.uni.fmi.mjt.burnout.plan.SemesterPlan;
import bg.sofia.uni.fmi.mjt.burnout.subject.UniversitySubject;


public abstract sealed class AbstractSemesterPlanner implements SemesterPlannerAPI
        permits ComputerScienceSemesterPlanner, SoftwareEngineeringSemesterPlanner {

    private static final int DAYS_PER_JAR = 5;

    @Override
    public int calculateJarCount(UniversitySubject[] subjects, int maximumSlackTime, int semesterDuration) {
        if(subjects == null){
            throw new IllegalArgumentException("Subjects cannot be null");
        }
        if(maximumSlackTime < 0){
            throw new IllegalArgumentException("Maximum slack time cannot be negative");
        }
        if(semesterDuration < 0){
            throw new IllegalArgumentException("Semester duration cannot be negative");
        }

        double totalRest = 0;
        int totalStudyTime = 0;
        for (UniversitySubject subject : subjects) {
            totalStudyTime += subject.neededStudyTime();
            totalRest += Math.ceil(subject.neededStudyTime() * subject.category().getRestCoefficient());
        }

        if (totalRest > maximumSlackTime) {
            throw new DisappointmentException("Maximum slack time exceeded");
        }

        int jarCount = totalStudyTime / DAYS_PER_JAR;

        if (semesterDuration > totalRest + totalStudyTime) {
            jarCount *= 2;
        }
        return jarCount;
    }

    protected void checkSubjectRequirements(SemesterPlan semesterPlan) throws InvalidSubjectRequirementsException {
        for (int i = 0; i < semesterPlan.subjectRequirements().length; i++) {
            for (int j = i + 1; j < semesterPlan.subjectRequirements().length; j++) {
                if(semesterPlan.subjectRequirements()[i].category().equals(semesterPlan.subjectRequirements()[j].category())){
                    throw new InvalidSubjectRequirementsException("Repeating Subject Requirements");
                }
            }
        }
    }

    protected void sortSubjectsByCreditsDescending(UniversitySubject[] subjects) {
        if (subjects == null || subjects.length <= 1) {
            return;
        }

        int n = subjects.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (subjects[j].credits() < subjects[j + 1].credits()) {
                    UniversitySubject temp = subjects[j];
                    subjects[j] = subjects[j + 1];
                    subjects[j + 1] = temp;
                }
            }
        }
    }

    protected void sortSubjectsByReviewsDescending(UniversitySubject[] subjects) {
        if (subjects == null || subjects.length <= 1) {
            return;
        }

        int n = subjects.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (subjects[j].rating() < subjects[j + 1].rating()) {
                    UniversitySubject temp = subjects[j];
                    subjects[j] = subjects[j + 1];
                    subjects[j + 1] = temp;
                }
            }
        }
    }
}
