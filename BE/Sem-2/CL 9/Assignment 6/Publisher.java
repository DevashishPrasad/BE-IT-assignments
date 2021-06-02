package pubsub1;

import javax.jms.*;
import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

public class Publisher {
	private static String url = ActiveMQConnection.DEFAULT_BROKER_URL;

	public static void main(String[] args) throws JMSException {
		ConnectionFactory connectionFactory = new ActiveMQConnectionFactory(url);
		Connection connection = connectionFactory.createConnection();
		connection.start();
// JMS messages are sent and received using a Session. We will
// create here a non-transactional session object. If you want
// to use transactions you should set the first parameter to 'true'
		Session session = connection.createSession(false, Session.AUTO_ACKNOWLEDGE);
		Topic topic = session.createTopic("CL9");
		MessageProducer producer = session.createProducer(topic);
// We will send a small text message saying 'Hello'
		TextMessage message = session.createTextMessage();
		message.setText("This is a Message for Topic CL9");
// Here we are sending the message!
		producer.send(message);
		System.out.println("Sent message '" + message.getText() + "'");
		connection.close();
                
                
                
                
                ConnectionFactory connectionFactory1 = new ActiveMQConnectionFactory(url);
		Connection connection1 = connectionFactory1.createConnection();
		connection1.start();
// JMS messages are sent and received using a Session. We will
// create here a non-transactional session object. If you want
// to use transactions you should set the first parameter to 'true'
		Session session1 = connection1.createSession(false, Session.AUTO_ACKNOWLEDGE);
		Topic topic1 = session1.createTopic("CL10");
		MessageProducer producer1 = session1.createProducer(topic1);
// We will send a small text message saying 'Hello'
		TextMessage message1 = session1.createTextMessage();
		message1.setText("This is a Message for Topic CL10");
// Here we are sending the message!
		producer1.send(message1);
		System.out.println("Sent message '" + message1.getText() + "'");
		connection1.close();
	}
}