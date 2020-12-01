import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Vector;


// Super class Account (Base class of Student and Admin)
class Account {
    // Name, Email and Password
    private String name, email, password;

    // Initialize name and email to NULL
    Account() {
        name = null;
        email = null;
	password = null;
    }

    // Methods to get Name, Email and Password
    public String getName() {
        /* Get Name */
        return null;
    }

    public String getEmail() {
        /* Get Email */
        return null;
    }

    public String getPassword() {
        /* Get Password */
        return null;
    }

    // Protected methods to set Name, Email and password provided 
    protected void setName(String name) {
        /* Set Name */
    }

    protected void setEmail(String email) {
        /* Set email */
    }

    protected void setPassword(String password) {
        /* Set password */
    }

    protected Boolean verifyAccount(String email, String password) {
        if (validaded(email, passsword))
        {   
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

    protected void addStudent() {
        /* add details of student */
    }

    protected void addTeacher() {
        /* add details of teacher */
    }

    protected void addSubject() {
        /* add subjects */
    }

    protected void addTemplate() {
        /* add template of questions */
    }

    protected void removeStudent() {
        /* add details of student */
    }

    protected void removeTeacher() {
        /* add details of teacher */
    }

    protected void removeSubject() {
        /* add subjects */
    }

    protected void removeTemplate() {
        /* add template of questions */
    }

    protected void generatePasswords() {
        /* generate passwords */
    }

    protected void addClass() {
        /* add class  */
    }
    
    protected void removeClass() {
        /* add class  */
    }    

    protected void generateReport() {
        /* generate passwords */
    }
}

class Student extends Account {
    // Attributes of student
    private int rollNo, year, division;

    // give feedback
    public void giveFeedback(String rollNo)
    {
        /* get feedback of student*/
    }
}

class Teacher {
    // Attributes of teacher
    private int teacherId, deptId;
    String teacherName

    protected void createTeacher() {
        /* add teacher */
    }
}

class Subject {

    private String subjectName;
    private int subjectId, deptId, year, domain;
   
    Subject(String subjectName, int subjectId, int deptId, int year, int domain)
    {
        //validating subject details
        if (validaded(subjectName))
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
    
    private Boolean validaded(String subjectName){return true;}
}

class Template extends Teacher, Subject{
    // Attributes of template
    private int teacherId, subjectId, year, division;
    String tempName

    protected void createTemplate() {
        /* add teacher */
    }

    protected void addQuestion() {
        /* add question */
    }
}

class Question extends Template{
    // Attributes of Question
    private int queId, noOptions;
    String questionPrompt, option1, option2, option3, option4, option5, tempName;

    protected void createQuestion() {
        /* add teacher */
    }
}

class Feedback extends Student, Template{
    // Attributes of feedback
   Template template;

    protected void updateFeedback() {
        /* add teacher */
    }
}

class Report {
    protected Boolean type;
    private Timestamp generate;
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
}

class Teacher_Report extends Report{
    private Vector<Teacher> teacher;
    //method for fetching data as per report type
    public void SingleQuries() {/* */};
    public void groupQuries() {/**/};
}

class Class_Report extends Report{
    private Vector<Class> class ;
    //method for fetching data as per report type
    public void SingleQuries() {/* */};
    public void groupQuries() {/* */};
}

class Student_Report extends Report{
    private Vector<Student> student ;
    //method for fetching data as per report type
    public void SingleQuries() {/* */};
    public void groupQuries() {/* */};
}

class Subject_Report extends Report{
    private Vector<Subject> subject ;
    //method for fetching data as per report type
    public void SingleQuries() {/* */};
    public void groupQuries() {/* */};
}

class Mapping{
}

public class main {
    public static void main(String[] args) {

    }
}
