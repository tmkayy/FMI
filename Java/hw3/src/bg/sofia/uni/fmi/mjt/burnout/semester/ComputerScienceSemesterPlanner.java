package bg.sofia.uni.fmi.mjt.burnout.semester;

import bg.sofia.uni.fmi.mjt.burnout.exception.CryToStudentsDepartmentException;
import bg.sofia.uni.fmi.mjt.burnout.exception.InvalidSubjectRequirementsException;
import bg.sofia.uni.fmi.mjt.burnout.plan.SemesterPlan;
import bg.sofia.uni.fmi.mjt.burnout.subject.UniversitySubject;

public final class ComputerScienceSemesterPlanner extends AbstractSemesterPlanner {
    @Override
    public UniversitySubject[] calculateSubjectList(SemesterPlan semesterPlan) throws InvalidSubjectRequirementsException {
        checkSubjectRequirements(semesterPlan);
        UniversitySubject[] subjects = semesterPlan.subjects();

        sortSubjectsByReviewsDescending(subjects);

        int totalCredits = 0;
        int count = 0;

        for (UniversitySubject subject : subjects) {
            totalCredits += subject.credits();
            count++;

            if (totalCredits >= semesterPlan.minimalAmountOfCredits()) {
                break;
            }
        }

        if (totalCredits < semesterPlan.minimalAmountOfCredits()) {
            throw new CryToStudentsDepartmentException("Cannot cover credits");
        }

        UniversitySubject[] chosen = new UniversitySubject[count];
        for (int i = 0; i < count; i++) {
            chosen[i] = subjects[i];
        }

        return chosen;
    }
}
