import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;


// Super class Account (Base class of Student and Admin)
class Account {
    // Name, Email and Password
    private String username, password;

    // Initialize name and email to NULL
    Account() {
        name = null;
	password = null;
    }

    // Methods to get Name, Email and Password
    public String getName() {
        /* Get Name */
        return null;
    }

    public String getPassword() {
        /* Get Password */
        return null;
    }

    // Protected methods to set Name, Email and password provided 
    protected void setName(String username) {
        /* Set Name */
    }

    protected void setPassword(String password) {
        /* Set password */
    }

    private boolean isValid(String username, String password) {
        if(quantity == NULL || password == NULL)
            return false;
        return true;
    }

    public Boolean verifyUser(String username, String password) {
	if (isValid(username, passsword))
        {   
        	this.username = username;
            	this.password = password;            
	    	return true;
        }
        else
        {
            // Error
	    return false;
        }	

}

class Admin extends Account {
    // Attribute of Admin
    private String name;

    // Get name of admin
    public String getName() {
        return null;
    }

    public void addStudent(int roll,int class_id) {
        /* add details of student */
    }

    public void addTeacher(int tid,String dept) {
        /* add details of teacher */
    }

    public void addSubject(int sub_id,String subj) {
        /* add subjects */
    }

    public void addTemplate(String temp_name) {
        /* add template of questions */
    }

    public void removeStudent(int roll,int class_id)	{
	/* remove student */
    }

    public void removeTeacher(int tid,String dept)	{
	/* remove teacher */
    }

    public void removeSubject(int sub_id,String subj)	{
	/* remove subject */
    }

    public void removeTemplate(String temp_name)	{
	/* remove template */
    }

    public void generatePasswords() {
        /* generate passwords */
    }

    protected void addClass(int year,String dept) {
        /* add class  */
    }

    public void removeClass(int year,String dept)	{
	/* remove class */
    }

    public void generateReport() {
        /* generate passwords */
    }
}

class Student extends Account {
    // Attributes of student
    private int rollNo, year, division;

    // give feedback
    public void giveFeedBack(int roll,int year,int div)
    {
        /* get feedback of student*/
    }
}

class Teacher {
    // Attributes of teacher
    private int teacherId, deptId;
    String name;

    public void createTeacher(int tid,int dept,String name) {
        /* add teacher */
    }

    public void removeTeacher(int tid,int dept) {
        /* add teacher */
    }
}

class Class1 {
    // Attributes of teacher
    private int year,division,dept,startRan,endRan;

    public void createClass(int startRan,int endRan) {
        /* create class */
    }

    public void removeClass(int startRan,int endRan) {
        /* remove class */
    }
}

class Subject {

    private String subjectName;
    private int subjectId, deptId, year, domain;
   
    private boolean isValid(String subjectName) {
        if(subjectName == NULL)
            return false;
        return true;
    }

    Subject(String subjectName, int subjectId, int deptId, int year, int domain)
    {
        //validating subject details
        if (isValid(subjectName))
        {   
            this.subjectName = subjectName;
            this.subjectId = subjectId;
            this.deptId = deptId;
            this.year = year;
            this.domain = domain;
        }
        else
        {
            // Error
        }
        
    }

    public void createSubject(int subid,String subj,int dept,int year) {
        /* add subject */
    }

    public void removeSubject(int subid,int dept, int year) {
        /* remove subject */
    }
}

class Template {
    // Attributes of template
    String tempName;

    public void createTemplate(String tempName) {
        /* create template */
    }

    public void addQuestion() {
        /* add question */
    }

    public void removeQuestion() {
        /* remove question */
    } 
}

class Question {
    // Attributes of Question
    private int qId, noOptions;
    String questionPrompt, option1, option2, option3, option4, option5, tempName;

    public void createQuestion(int qid,int [] options) {
        /* create question */
    }

    public void removeQuestion(int qid) {
        /* remove question */
    }
}

class Feedback {
    // Attributes of feedback
   Template template;

    public void UpdateFeedback(int cat,int score) {
        /* update feedback */
    }
}

class Report {
    private Timestamp generate;
    private int report_id,year,division,teacherid,subjectid;
    protected Date start_date, end_date;

    Report()
    {
        // Registering the time of Report generation
        Date date = new Date();
        long time = date.getTime();
        this.generate  = new Timestamp(time);
    }

    // Setter Methods
    public void setReportType(Boolean type) {
        this.type = type;
    }

    // Setter Method used for defining the start date and end date of the report
    public void setDuration(Date start_date, Date end_date) {
        this.start_date = start_date;
        this.end_date = end_date;
    }

    public void createReport(int reportid) {
        /* create report */
    }

    public void downLoadReport(int reportid) {
        /* download report */
    }
}

class Mapping {
    private int year,divisin,teacherid,subjectid;
    
    public void createMapping() {
        /* create mapping */
    }

    public void removeMapping() {
        /* remove mapping */
    }
}

public class main {
    public static void main(String[] args) {

    }
}
