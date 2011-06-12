package test;

import org.jclouds.blobstore.BlobStore;
import org.jclouds.blobstore.BlobStoreContext;
import org.jclouds.blobstore.BlobStoreContextFactory;
import org.jclouds.blobstore.domain.Blob;
import org.jclouds.s3.S3Client;
import org.jclouds.s3.domain.S3Object;

//import static org.jclouds.aws.s3.options.PutObjectOptions.Builder.withAcl;

public class MainTest {

	public static void main(String[] args) {

		String accesskeyid = "";
		String secretkey = "";
		String bucket = "";

		// get a context with amazon that offers the portable BlobStore api
		BlobStoreContext context = new BlobStoreContextFactory().createContext(
				"aws-s3", accesskeyid, secretkey);

		// create a container in the default location
		BlobStore blobStore = context.getBlobStore();

		blobStore.createContainerInLocation(null, bucket);

		// add blob
		Blob blob = blobStore.newBlob("test");
		blob.setPayload("test data");
		blobStore.putBlob(bucket, blob);

		// when you need access to s3-specific features, use the
		// provider-specific context
		S3Client s3Client = S3Client.class.cast(//
				context.getProviderSpecificContext().getApi());

		// make the object world readable
		String publicReadWriteObjectKey = "public-read-write-acl";
		S3Object object = s3Client.newS3Object();
		object.getMetadata().setKey(publicReadWriteObjectKey);
		object.setPayload("hello world");

		// s3Client.putObject(bucket, object,
		// withAcl(CannedAccessPolicy.PUBLIC_READ));

		context.close();

	}

}
