
package com.amazonaws.sqs.generated;

import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.xml.ws.Service;
import javax.xml.ws.WebEndpoint;
import javax.xml.ws.WebServiceClient;
import com.amazonaws.sqs.generated.MessageQueuePortType;
import com.amazonaws.sqs.generated.MessageQueuePortType;

/**
 * This class was generated by the CXF 2.0-incubator
 * Wed Dec 19 16:11:11 PST 2007
 * Generated source version: 2.0-incubator
 * 
 */

@WebServiceClient(name = "MessageQueue", targetNamespace = "http://queue.amazonaws.com/doc/2008-01-01/", wsdlLocation = "file:/tmp/20080101/QueueService_20080101.wsdl")
public class MessageQueue extends Service {

    private final static URL WSDL_LOCATION;
    private final static QName SERVICE = new QName("http://queue.amazonaws.com/doc/2008-01-01/", "MessageQueue");
    private final static QName MessageQueueHttpsPort = new QName("http://queue.amazonaws.com/doc/2008-01-01/", "MessageQueueHttpsPort");
    private final static QName MessageQueuePort = new QName("http://queue.amazonaws.com/doc/2008-01-01/", "MessageQueuePort");
    static {
        URL url = null;
        try {
            url = new URL("http://aws-sqs2-fe-gamma.amazon.com/doc/2008-01-01/QueueService.wsdl");
        } catch (MalformedURLException e) {
            System.err.println("Can not initialize the default wsdl from http://aws-sqs2-fe-gamma.amazon.com/doc/2008-01-01/QueueService.wsdl");
            // e.printStackTrace();
        }
        WSDL_LOCATION = url;
    }

    public MessageQueue(URL wsdlLocation, QName serviceName) {
        super(wsdlLocation, serviceName);
    }

    public MessageQueue() {
        super(WSDL_LOCATION, SERVICE);
    }

    /**
     * 
     * @return
     *     returns MessageQueueHttpsPort
     */
    @WebEndpoint(name = "MessageQueueHttpsPort")
    public MessageQueuePortType getMessageQueueHttpsPort() {
        return (MessageQueuePortType)super.getPort(MessageQueueHttpsPort, MessageQueuePortType.class);
    }
    /**
     * 
     * @return
     *     returns MessageQueuePort
     */
    @WebEndpoint(name = "MessageQueuePort")
    public MessageQueuePortType getMessageQueuePort() {
        return (MessageQueuePortType)super.getPort(MessageQueuePort, MessageQueuePortType.class);
    }

}
