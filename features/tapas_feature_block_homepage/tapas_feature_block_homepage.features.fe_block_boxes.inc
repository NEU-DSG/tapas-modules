<?php
/**
 * @file
 * tapas_feature_block_homepage.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function tapas_feature_block_homepage_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Home page 4 components';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_4_components';
  $fe_block_boxes->body = '<div class="col-md-3 pillars"><div class="center-block text-center"><h2>Archive</h2><i class="fa fa-inbox fa-5x"></i><p class="text-left">House your TEI data in the TAPAS Commons repository for secure, long-term storage and access.</p><p><a class="btn btn-default" href="#" role="button" id="more-archive" data-toggle="modal" data-target="#archive-info">More &raquo;</a></p></div></div>
<div class="col-md-3 pillars"><div class="center-block text-center"><h2>Discover</h2><i class="fa fa-search fa-5x"></i><p class="text-left">Research TEI projects and content through an XML aware search interface.</p><p><a class="btn btn-default" href="#" role="button" id="more-discover" data-toggle="modal" data-target="#discover-info">More &raquo;</a></p></div></div>
<div class="col-md-3 pillars"><div class="center-block text-center"><h2>Publish</h2><i class="fa fa-bar-chart fa-5x"></i><p class="text-left">Display, Curate, and Analyze your own and others\' TEI project data.</p><p><a class="btn btn-default" href="#" role="button" id="more-publish" data-toggle="modal" data-target="#publish-info">More &raquo;</a></p></div></div>
<div class="col-md-3 pillars"><div class="center-block text-center"><h2>Share</h2><i class="fa fa-share-alt fa-5x"></i><p class="text-left">Engage with an open, collaborative community of TEI practitioners and researchers.</p><p><a class="btn btn-default" href="#" role="button" id="more-share" data-toggle="modal" data-target="#share-info">More &raquo;</a></p></div></div>


<div class="modal fade" id="archive-info">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">ARCHIVE</h4>
      </div>
      <div class="modal-body">
				<div class="row">
	  			<div class="col-md-2"></div>
					<div class="col-md-4">
						<p>TAPAS provides free, open-access, and long-term archiving of users\' TEI data. The central TAPAS <a href="http://tapasproject.org/data-commons">Data Commons</a> is supported by the <a href="http://#">Digital Repository Service (DRS)</a> at Northeastern University.</p>
						<p>TAPAS also offers temporary storage and retrieval of "test" data, perfect for workshop and classroom TEI data generation scenarios.</p>
					</div>
					<div class="col-md-4">
						<p>Begin archiving and sharing your TEI data today!</p>
						<p><a href="" class="btn btn-lg btn-default">Display Your TEI</a></p>
					</div>
				</div>
			</div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" id="discover-info">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">DISCOVER</h4>
      </div>
      <div class="modal-body">
				<div class="row">
					<div class="col-md-2"></div>
					<div class="col-md-4">
						<p>TAPAS is in the process of developing a dynamic, XML aware research interface that will extend users\' current ability to locate and study the literary content of our repository to include querying and analyzing TEI as a primary source</p>
						<p></p>
					</div>
					<div class="col-md-4">
						<p><em>Discover</em> today!<br>| the TAPAS advanced search interface <br>| Featured <em>projects</em>, <em>collections</em>, and <em>items</em> <br> | the DATA Commons</p>
						<p><a href="http://tapasproject.org/discover" class="btn btn-lg btn-default" style="background-color:orange; color: white;">Discover</a></p>
					</div>
				</div>
			</div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<div class="modal fade" id="publish-info">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">PUBLISH</h4>
      </div>
      <div class="modal-body">
				<div class="row">
					<div class="col-md-2"></div>
					<div class="col-md-4">
						<p>TAPAS offers TEI projects low-cost publishing services with its TAPAS | TEI-C memberships. By registering with the <a href="http://www.tei-c.org/index.xml">TEI-C</a>, project managers can curate and publish their TEI data as projects and collections. </p>
						<p>Users can invite other participants to collaborate on their projects, edit permissions for collaborators, and include support files to accompany their project data (including <a href="http://tapasproject.org/faq/#images">image</a> files and <a href="http://tapasproject.org/faq/#ography">Ography files</a>.</p>
					</div>
					<div class="col-md-4">
						<p>Begin managing and publishing your own TEI projects today!</p><p>Learn more about TAPAS | TEI-C accounts <a href="http://tapasproject.org/about/#tei">here</a>.</p>
						<p><a href="" class="btn btn-lg btn-default" style="background-color: #5BC0DE;">Sign Up</a></p>
					</div>
				</div>
			</div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->


<div class="modal fade" id="share-info">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">SHARE</h4>
      </div>
      <div class="modal-body">
				<div class="row">
					<div class="col-md-2"></div>
					<div class="col-md-3">
						<p>Do you have questions about the TEI? Are you looking to learn more about best practices and developments in markup, schema development, metadata, Ography and support files management? Go to the TAPAS <a href="http://tapasproject.org/community">Community</a>page to access our TAPAS | Learn features:</p>
							<dl>
  							<dt>Forums</dt>
  								<dd>The TAPAS forums are run by active members of our community. To view and contribute to our forums, visit our community <a href="http://tapasproject.org/community/#forums">forums</a> today!</dd>
  							<dt>Resources</dt>
  								<dd>Check out our <a href="http://tapasproject.org/support/resources">Resources</a> page to access our FAQ and TEI support documentation.</dd>
  							<dt>Workshops</dt>
  								<dd>TAPAS offers workshops on the TEI and TAPAS support services. <a href="tapasproject.org/workshops">Register</a> for a scheduled workshop today! If you would like to host your own TAPAS workshop at your local institution, you can learn more <a href="tapasproject.org/workshops">here</a>.</dd>
  						</dl>
  				</div>
				  <div class="col-md-3">
					  <dl>
						  <dt>Code-Alongs</dt>
						  <dd>Code-Alongs are a free support workshop series that provides users guided support for developing their markup to make the best use of advanced features of the TAPAS research and publishing platform. <a href="tapasproject.org/workshops">Register</a> for a scheduled Code-Along today! If you would like to propose a Code-Along topic, please visit the <a href="tapasproject.org/code-alongs">Code-Along Forum</a>.</dd>
						  <dt>Clinics</dt>
						  <dd>TAPAS Clinics are regularly held virtual office hours to answer the TAPAS community\'s TEI and project building questions. To sign-up for a TAPAS Code-Along, please <a href="tapasproject.org/clinics">view the schedule</a></dd>
						  <dt>TAPAS | Classroom</dt>
						  <dd>Learn more about the future services of the TAPAS <a href="http://tapasproject.org/classroom">Classroom.</a></dd>
						</dl>
					</div>
					<div class="col-md-3">
						<p>Teach, Learn, Share today!</p>
						<p><a href="" class="btn btn-lg btn-default" style="background-color: orange;">TAPAS | Learn</a></p>
					</div>
				</div>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->
';

  $export['home_page_4_components'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Home page bottom content';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_bottom';
  $fe_block_boxes->body = '<section class="testimonials"><div class="container"><div class="row"><div class="col-sm-12"><h2>Testimonials</h2></div></div><div class="row"><div class="col-sm-4"><blockquote><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p><footer>Someone famous in <cite title="Source Title">Source Title</cite></footer></blockquote></div><div class="col-sm-4 testimonial"><blockquote><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p><footer>Someone famous in <cite title="Source Title">Source Title</cite></footer></blockquote></div><div class="col-sm-4 testimonial"><blockquote><p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p><footer>Someone famous in <cite title="Source Title">Source Title</cite></footer></blockquote></div></div></div></section><hr><section class="membership"><div class="container"><div class="row"><div class="col-sm-12"><h2>Membership</h2></div></div><div class="row"><div class="col-sm-6 col-sm-offset-3"><table class="table table-bordered"><tr><th></th><th>Free Tapas Membership</th><th>Tapas and TEI Membership</th></tr><tr><td>Cost</td><td>Free</td><td>Paid</td></tr><tr><td>Contribute to Projects</td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr><tr><td>Create Projects</td><td></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr><tr><td>Contribute to Collections</td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr><tr><td>Create Collections</td><td></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr><tr><td>Be Invited to Collaborate on existing projects and collections</td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr><tr><td>Invite others to Collaborate on existing projects and collections</td><td></td><td><span class="fa-stack fa-lg"><i class="fa fa-circle fa-stack-2x"></i><i class="fa fa-check fa-stack-1x fa-inverse"></i></span></td></tr></table></div></div></div></section><section class="sponsors"><div class="container"><div class="row"><div class="col-sm-12"><h3>Generously Funded By</h3></div></div><div class="row"><div class="col-sm-4"><img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/tei_white.png" class="logo"></div><div class="col-sm-4"><img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/imls_white.png" class="logo"></div><div class="col-sm-4"><img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/neh_white.png" class="logo neh"></div></div></div></section>';

  $export['home_page_bottom'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Home page header content';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_header';
  $fe_block_boxes->body = '<section class="header"><div class="container-fluid"><div class="row"><div class="col-lg-8"><h1 class="text-center"><a class="logo" href="/" title="Home"><img  src="http://tapasdev.neu.edu/profiles/buildtapas/themes/tapas-themes/tapas_redesign/logo.png" alt="Home"></a><em>Archive, Publish, and Share Your TEI</em></h1><h4 class="text-right">. . . through the TEI Archive, Publishing, and Access Service</h4><p>&nbsp;</p><div class="row"><div class="col-sm-3 col-sm-offset-2 col-md-offset-3"><a href="" class="btn btn-lg btn-info btn-block">Sign Up</a></div><div class="col-sm-4 col-sm-offset-1"><a href="" class="btn btn-lg btn-default btn-block">Display Your TEI</a></div></div></div><!-- /.col-lg-8 --><div class="col-lg-4"><div class="block"><p>TAPAS is a digital project hosted by Northeastern University’s Digital Scholarship Group and Digital Repository Service. </p><p>We are generously funded by the Text Encoding Initiative Consortium (TEI-C), the Institute of Museum and Library Sciences (IMLS), and the National Endowment for the Humanities (NEH).</p></div></div></div></div></section>';

  $export['home_page_header'] = $fe_block_boxes;

  return $export;
}
