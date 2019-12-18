Authors: Raymond Khazoum, Margaux Mannaerts, Edgar Badalyan

This project is an implementaion of the Smith-Waterman algorithm for protein sequences, with an affine gap penalty.

Mandatory parameters (in correct order):
	* database file name
	* query sequence file name

Optional parameters (in any order):
	* with flag "-go": gap open penalty (default: 11)
	* with flag "-ge": gap extension penalty (default: 1)
	* with flag "-b": blosum matrix file name (default: BLOSUM62)
	* with flag "-f": score factor (default: 12)

Score factor is needed to determine which scores to include in the output. A sequence with a score s is include if:
s > max_score/factor, where max_score is the score of the alignment of the query sequence with itself.
