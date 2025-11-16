package bg.sofia.uni.fmi.mjt.show.elimination;

import bg.sofia.uni.fmi.mjt.show.ergenka.Ergenka;

public class PublicVoteEliminationRule implements EliminationRule {

    private final String[] votes;

    public PublicVoteEliminationRule(String[] votes) {
        this.votes = votes;
    }

    public String[] getVotes() {
        return votes;
    }

    @Override
    public Ergenka[] eliminateErgenkas(Ergenka[] ergenkas) {
        if (ergenkas == null || ergenkas.length == 0) {
            return ergenkas;
        }
        int[] counts = new int[ergenkas.length];
        for (int i = 0; i < ergenkas.length; i++) {
            for (String vote : votes) {
                if (ergenkas[i].getName().equals(vote))
                    counts[i]++;
            }
        }
        boolean eliminate = false;
        for (int i = 0; i < votes.length; i++) {
            if (counts[i] > votes.length / 2) {
                eliminate = true;
                break;
            }
        }
        if (!eliminate)
            return ergenkas;
        else {
            Ergenka[] newErgenkas = new Ergenka[counts.length - 1];
            int newErgenkaIndex = 0;
            for (int i = 1; i < counts.length; i++) {
                if (counts[i] <= votes.length / 2)
                    newErgenkas[newErgenkaIndex++] = ergenkas[i];
            }
            return newErgenkas;
        }
    }
}
