#pragma once
#include "lve_device.hpp"


#include <string>
#include <vector>


namespace lve
{
    struct PipelineConfigInfo {
        PipelineConfigInfo() = delete;
        PipelineConfigInfo(const PipelineConfigInfo&) = delete;
       
        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        std::vector<VkDynamicState> dynamicStatesEnables;
        VkPipelineDynamicStateCreateInfo dynamicStateInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };
    
    class LvePipeline
    {
        public:
            LvePipeline(
                LveDevice &devide,
                const std::string& vertFilePath,
                const std::string& fragFilePath, 
                const PipelineConfigInfo& configInfo
            );

            LvePipeline(const std::string& vertFilePath, const std::string& fragFilePath);
            ~LvePipeline();
            LvePipeline(const LvePipeline&) = delete;
            LvePipeline& operator=(const LvePipeline&) = delete;

            void bind(VkCommandBuffer commandBuffer);

            static void defaultPipelineConfigInfo(PipelineConfigInfo& configInfo);

        private:
            static std::vector<char> readFile(const std::string& filePath);
            void createGraphicsPipeline(
                const std::string& vertFilePath,
                const std::string& fragFilePath,
                const PipelineConfigInfo& configInfo
                );

            void createShaderModule(const std::vector<char>& code, VkShaderModule& shaderModule);

            LveDevice& lveDevice;
            VkPipeline graphicsPipeline;
            VkShaderModule vertShaderModule;
            VkShaderModule fragShaderModule;
    };
}