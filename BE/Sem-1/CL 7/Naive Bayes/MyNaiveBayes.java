/**
 * Assignment 8 : Use Java Weka API to train a NaiveBayes classifiers on Iris data set
 * @author Ayan Gadpal 
 * Batch: P-11 
 * Roll No. 43308
 * Created on: Nov 25, 2020
 */



import java.io.*;

import weka.classifiers.bayes.NaiveBayes;
import weka.classifiers.Evaluation;
import weka.core.Instances;
import weka.core.Debug;

public class MyNaiveBayes {

	public static void main(String[] args) throws Exception {

		//read the arff file or dataset the data
		BufferedReader trReader = new BufferedReader(new FileReader("iris.arff"));
		Instances dataset = new Instances(trReader);
		trReader.close();


		// Divide dataset to train dataset 80% and test dataset 20%
		int trainSize = (int) Math.round(dataset.numInstances() * 0.8);
		int testSize = dataset.numInstances() - trainSize;

		dataset.randomize(new Debug.Random(1));
		

		Instances training = new Instances(dataset, 0, trainSize);
		Instances testing = new Instances(dataset, trainSize, testSize);
		
		training.setClassIndex(training.numAttributes() - 1);
		testing.setClassIndex(testing.numAttributes() - 1);
		
		NaiveBayes nB = new NaiveBayes();
		nB.buildClassifier(training);
		System.out.println(nB);
		
		Evaluation eval = new Evaluation(testing);
		eval.evaluateModel(nB, testing);
		System.out.println(eval.toSummaryString("\nResults Testing\n", true));
		
		for(int i = 0; i < training.numClasses(); i++) {
			System.out.println("Class "+ i);
			System.out.println(eval.precision(i) + " " + eval.recall(i) + " " + eval.areaUnderROC(i));
		}
		
	}

}
