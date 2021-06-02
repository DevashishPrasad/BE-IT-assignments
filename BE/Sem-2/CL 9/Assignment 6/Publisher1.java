package pubsub1;

import javax.jms.*;
import org.apache.activemq.ActiveMQConnection;
import org.apache.activemq.ActiveMQConnectionFactory;

public class Publisher1 {
	private static String url = ActiveMQConnection.DEFAULT_BROKER_URL;

	public static void main(String[] args) throws JMSException {
		ConnectionFactory connectionFactory2 = new ActiveMQConnectionFactory(url);
		Connection connection2 = connectionFactory2.createConnection();
		connection2.start();
// JMS messages are sent and received using a Session. We will
// create here a non-transactional session object. If you want
// to use transactions you should set the first parameter to 'true'
		Session session2 = connection2.createSession(false, Session.AUTO_ACKNOWLEDGE);
		Topic topic2 = session2.createTopic("IOT_Lab");
		MessageProducer producer2 = session2.createProducer(topic2);
// We will send a small text message saying 'Hello'
		TextMessage message = session2.createTextMessage();
		message.setText("This is a Message for Topic IOT_Lab");
// Here we are sending the message!
		producer2.send(message);
		System.out.println("Sent message '" + message.getText() + "'");
		connection2.close();
	}
}