package bg.sofia.uni.fmi.mjt.burnout.semester;

import bg.sofia.uni.fmi.mjt.burnout.exception.CryToStudentsDepartmentException;
import bg.sofia.uni.fmi.mjt.burnout.exception.InvalidSubjectRequirementsException;
import bg.sofia.uni.fmi.mjt.burnout.plan.SemesterPlan;
import bg.sofia.uni.fmi.mjt.burnout.subject.SubjectRequirement;
import bg.sofia.uni.fmi.mjt.burnout.subject.UniversitySubject;

public final class SoftwareEngineeringSemesterPlanner extends AbstractSemesterPlanner{
    @Override
    public UniversitySubject[] calculateSubjectList(SemesterPlan semesterPlan) throws InvalidSubjectRequirementsException {
        checkSubjectRequirements(semesterPlan);
        SubjectRequirement[] requirements = semesterPlan.subjectRequirements();
        UniversitySubject[] subjects = semesterPlan.subjects();

        sortSubjectsByCreditsDescending(subjects);

        int totalSubjectsNeeded = 0;
        for (SubjectRequirement req : requirements) {
            totalSubjectsNeeded += req.minAmountEnrolled();
        }

        UniversitySubject[] chosen = new UniversitySubject[totalSubjectsNeeded];
        int write = 0;

        for (SubjectRequirement req : requirements) {
            int count = 0;

            for (UniversitySubject subject : subjects) {
                if (subject.category().equals(req.category())) {
                    chosen[write++] = subject;
                    count++;
                    if (count == req.minAmountEnrolled()) break;
                }
            }
        }

        if (!canCoverCredits(chosen, semesterPlan.minimalAmountOfCredits())) {
            throw new CryToStudentsDepartmentException("Cannot cover credits");
        }

        return chosen;
    }

    private boolean canCoverCredits(UniversitySubject[] chosenSubjects, int minimalCredits) {
        if (chosenSubjects == null) {
            return false;
        }

        int totalCredits = 0;
        for (UniversitySubject subject : chosenSubjects) {
            totalCredits += subject.credits();
        }

        return totalCredits >= minimalCredits;
    }
}
