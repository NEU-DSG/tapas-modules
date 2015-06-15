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
  $fe_block_boxes->info = 'Home page bottom content';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'home_page_bottom';
  $fe_block_boxes->body = '
  <section class="testimonials">
    <div class="container">
      <div class="row">
        <div class="col-sm-12">
          <h2>Testimonials</h2>
        </div>
      </div>
      <div class="row">
        <div class="col-sm-4">
          <blockquote>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p>
            <footer>Someone famous in <cite title="Source Title">Source Title</cite></footer>
          </blockquote>
        </div>
        <div class="col-sm-4 testimonial">
          <blockquote>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p>
            <footer>Someone famous in <cite title="Source Title">Source Title</cite></footer>
          </blockquote>
        </div>
        <div class="col-sm-4 testimonial">
          <blockquote>
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer posuere erat a ante.</p>
            <footer>Someone famous in <cite title="Source Title">Source Title</cite></footer>
          </blockquote>
        </div>
      </div>
    </div>
  </section>

  <hr>

  <section class="membership">
    <div class="container">
      <div class="row">
        <div class="col-sm-12">
          <h2>Membership</h2>
        </div>
      </div>
      <div class="row">
        <div class="col-sm-6 col-sm-offset-3">
          <table class="table table-bordered">
            <tr>
              <th></th><th>Free Tapas Membership</th><th>Tapas and TEI Membership</th>
            </tr>
            <tr>
              <td>Cost</td>
              <td>Free</td>
              <td>Paid</td>
            </tr>
            <tr>
              <td>Contribute to Projects</td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
            <tr>
              <td>Create Projects</td>
              <td>

              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
            <tr>
              <td>Contribute to Collections</td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
            <tr>
              <td>Create Collections</td>
              <td>

              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
            <tr>
              <td>Be Invited to Collaborate on existing projects and collections</td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
            <tr>
              <td>Invite others to Collaborate on existing projects and collections</td>
              <td>

              </td>
              <td>
                <span class="fa-stack fa-lg">
                  <i class="fa fa-circle fa-stack-2x"></i>
                  <i class="fa fa-check fa-stack-1x fa-inverse"></i>
                </span>
              </td>
            </tr>
          </table>
        </div>
      </div>
    </div>
  </section>

  <section class="sponsors">
    <div class="container">
      <div class="row">
        <div class="col-sm-12">
          <h3>Generously Funded By</h3>
        </div>
      </div>
      <div class="row">
        <div class="col-sm-4">
          <img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/tei_white.png" class="logo">
        </div>
        <div class="col-sm-4">
          <img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/imls_white.png" class="logo">
        </div>
        <div class="col-sm-4">
          <img src="/profiles/buildtapas/themes/tapas-themes/tapas_redesign/assets/images/neh_white.png" class="logo neh">
        </div>
      </div>
    </div>
  </section>';

  $export['home_page_bottom'] = $fe_block_boxes;

  return $export;
}
