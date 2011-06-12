package test;

import java.io.File;

import org.apache.commons.io.FileUtils;
import org.jclouds.blobstore.BlobStore;
import org.jclouds.blobstore.BlobStoreContext;
import org.jclouds.blobstore.BlobStoreContextFactory;
import org.jclouds.blobstore.domain.Blob;

//import static org.jclouds.aws.s3.options.PutObjectOptions.Builder.withAcl;

public class MainTest {

	public static void main(String[] args) throws Exception {

		String userHome = System.getProperty("user.home");

		File idFile = new File(userHome + "/"
				+ ".amazon/carrot/Access_Key_ID.txt");
		File keyFile = new File(userHome + "/"
				+ ".amazon/carrot/Secret_Access_Key.txt");

		String accessKeyId = FileUtils.readFileToString(idFile).trim();
		String secretAccessKey = FileUtils.readFileToString(keyFile).trim();

		String bucket = "tes-bucket";

		// get a context with amazon that offers the portable BlobStore api
		BlobStoreContext context = new BlobStoreContextFactory().createContext(
				"aws-s3", accessKeyId, secretAccessKey);

		// create a container in the default location
		BlobStore blobStore = context.getBlobStore();

		blobStore.createContainerInLocation(null, bucket);

		// add blob
		Blob blob = blobStore.newBlob("name-test");
		blob.setPayload("this test data");
		blobStore.putBlob(bucket, blob);

		// when you need access to s3-specific features, use the
		// provider-specific context
		// S3Client s3Client = S3Client.class.cast(//
		// context.getProviderSpecificContext().getApi());

		// make the object world readable
		// String publicReadWriteObjectKey = "public-read-write-acl";
		// S3Object object = s3Client.newS3Object();
		// object.getMetadata().setKey(publicReadWriteObjectKey);
		// object.setPayload("hello world");

		// s3Client.putObject(bucket, object,
		// withAcl(CannedAccessPolicy.PUBLIC_READ));

		context.close();

	}

}
